//using TCut

void write()
{
	TFile *output = new TFile("tut20.root", "recreate");
	
	TTree *tree = new TTree("tree", "tree");
	
	double x, y;
	
	tree->Branch("x",&x, "x/D");
	tree->Branch("y",&y, "y/D");
	
	
	//as an example of what TCut does. We are creating random data in x, with y proportial to x.
	
	TRandom2 *r = new TRandom2();
		
	for(int i=0; i<1e6; i++)
	{
		x = 1+r->Rndm()*9;
		y = x*2;
		tree->Fill();
	}
	
	output->Write();
	output->Close();
	
}


void cut()
{
	//define the cuts
	TCut cut2 = "x < 6";
	TCut cut1 = "x > 5";
	TCut cut3 = "x < 5";
	TCut cut4 = "x > 6";
	

	//output the hist automatically
	TFile *input = new TFile("tut20.root", "read");  //reads the file out
	
	TTree *tree = (TTree*)input->Get("tree");	//specifying which tree we want
	
	//tree->Draw("y"); 			//default draw all

	
	
	//drawing the cuts in multiple plots on 1 canvas
	auto c = new TCanvas("MyCanvas", "hists", 2400, 800);
	c->Divide(3,1);
	c->cd(1);
	tree->Draw("y", cut1);		//draw with cut1
	c->cd(2);
	tree->Draw("y", cut1&&cut2); 	//draw with & connection
	c->cd(3);
	tree->Draw("y", cut3||cut4); //draw with or connection


}



void tut20()
{
	write();
	cut();
}
