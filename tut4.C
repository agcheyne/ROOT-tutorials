//drawing graphs from data

void tut4()
{
	

	TGraph *gr = new TGraph(); // if we don't know how many input, can remove in constructor for empty tgrah

	gr->SetMarkerStyle(kFullCircle);
	gr->SetLineWidth(2);
	gr->SetLineColor(kRed);
	gr->SetMarkerSize(1);

	gr->SetTitle("Graph");
	gr->GetXaxis()->SetTitle("X values");
	gr->GetYaxis()->SetTitle("Y values");

	fstream file;
	file.open("data2.txt", ios::in);

	while(1) //1 will run forever

	{
	
		double x, y;
		file >> x >> y;
		gr->SetPoint(gr->GetN(), x, y);
		if(file.eof()) break;
		
	}


	file.close();	

	TCanvas *c1 = new TCanvas();
	
	gr->Draw("ALP"); // A for draw all, L for style (L=connected points, C=curve), P makes points,
}
