//CERN ROOT tutorial 17
//Storing data in TTree

void tut15()
{
	fstream file;
	file.open("data4.txt", ios::in);
	
	double x,y;
	
	TFile *output = new TFile("data4.root", "RECREATE");  //creating a new file
	
	TTree *tree = new TTree("tree","tree"); 		//creating the tree (name, title)
	tree->Branch("x", &x, "x/D");		//defining the branches	//syntax: (name in tree, reference the var, tell root if double/float/int)
	tree->Branch("y", &y, "y/D");		
	
	while(1)
	{
	
		file >> x >> y;
		
		if(file.eof()) break;
		
		cout << x << " " << y << endl;
		
		tree->Fill();	//have to have this in the while loop
	}
	
	output->Write();
	output->Close();
	
	file.close();


}
