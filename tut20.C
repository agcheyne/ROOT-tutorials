//using TCut

void write()
{
	TFile *output = new TFile("tut20.root", "recreate");
	
	TTree *tree = new TTree("tree", "tree");
	
	double x, y;
	
	tree->Branch("x",&x, "x/D");
	tree->Branch("y",&y, "y/D");
	
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

/360*pi

void cut()

{

	TFile *input = new TFile("tut20.root", "read");
	
	TTree *tree = (TTree*)input->Get("tree");
}



void tut20()
{
	write();
	//read();
}
