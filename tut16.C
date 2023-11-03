void tut16()
{

	TCanvas *c1 = new TCanvas();	
	
	TFile *input = new TFile("data4.root", "read");


	TTree *tree = (TTree*)input->Get("tree");
	
	
	double x,y;
	
	tree->SetBranchAddress("x",&x); //(name that we want to access, variable)
	tree->SetBranchAddress("y",&y);
	
	int entries = tree->GetEntries();
	
	cout << entries << endl;
	
	TH1F *hist = new TH1F("hist", "Histogram", 20, 0, 20);
	
		
	for(int i=0; i<entries; i++)
	{
		tree->GetEntry(i);
		
		hist->Fill(x);
		
		cout << x << " " << y << endl;
	}

	hist->Draw();	
	
	//input->Close();

}
