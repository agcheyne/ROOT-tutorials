//2D histograms

void tut17()

{
 	TH2F *hist = new TH2F("hist", "Histogram title", 100, -1, 1, 100, -1, 1);  ///(name, title, bins x, min x, max x, bins y, min y, max y)
 	
 	
 	//styles for hist
 	gStyle->SetPalette(kRainBow);
 	hist->SetContour(1000); //default is just 10, 1000 for smooth
 	hist->GetXaxis()->SetTitle("x [cm]");
 	hist->GetYaxis()->SetTitle("y [cm]");
 	hist->GetZaxis()->SetTitle("Entries");
 	
 	hist->SetStats(0);
 	
 	TRandom *rand = new TRandom(10); // (10 is arbitrary choice of seed)
 	
 	for(int i =0; i < 1e7; i++)
 	{
 		double x = rand->Gaus();
 		double y = rand->Gaus();
 		
 		hist->Fill(x,y);
 	
 	}
 	
 	hist->Draw("colz"); 	//default 2d is a scatter, colz gives zaxis. 
 	
}
