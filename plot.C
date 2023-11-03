void plot()
{
	TFile *file = new TFile("output.root", "READ");
	
	
	//histogram from the file
	//This code revrieves a histogram named "hist" from the ROOT file and assigns it to a pointer named hist
	//(TH1F*) syntax is used to cast the retrieved object to a THF1 object.
	TH1F *hist = (TH1F*)file->Get("hist"); 
	
	hist->Draw();
	
	//file->Close();

}
