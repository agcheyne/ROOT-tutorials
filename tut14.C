// CERN ROOT Tutorial 16
// Storing and Loading objects with TFile

void tut14()
{
	TFile *file = new TFile("output.root", "RECREATE"); //create fill to store before creating histogram   // TFile(file name, flag) 
	
	//everything which follows will attach to this file
	
	TH1F *hist = new TH1F("hist", "Historgram",100, 0, 100);
	
	hist->Fill(11);
	hist->Fill(90);


	//writing to the file
	file->Write();
	file->Close();
}
