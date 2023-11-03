//beautifying canvas

void tut9()
{
	//TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 13); //defining the historgram (name, title, bins, min, max)
	TH1F *hist = new TH1F("hist", "", 100, 0, 13); //same as above with no title if publication requires
	
	TRandom2 *rand = new TRandom2(3);
	
	
	//creating a file for output
	fstream file;
	file.open("data.txt", ios::out);
	
	
	
	//generating random data
	for (int i = 0; i < 1000; i++)
	{
		double r = rand->Gaus(5,1);  // (mean val, stdev)
		file << r << endl;
	}

	file.close();



	//fstream file;
	file.open("data.txt", ios::in);

	double value;

	while(1)
	{
		file >> value;
		hist->Fill(value);
		if(file.eof()) break;
	}

	file.close();
	
	hist->SetFillColor(kGreen-9); 	// filling the hist  	//can use +/9 to change intensity of fill
	
	
	hist ->GetXaxis() ->SetTitle("Distribution"); //setting axis
	hist ->GetYaxis() ->SetTitle("Entries"); 
	
	hist ->GetXaxis()->SetTitleSize(0.05);		//making larger text for x/y axis
	hist ->GetYaxis()->SetTitleSize(0.05);
	hist ->GetXaxis()->SetLabelSize(0.05);
	hist ->GetYaxis()->SetLabelSize(0.05);

	TF1 *fit = new TF1("fit", "gaus", 0, 13); // (name, fit, min,max of fit)
	fit->SetLineWidth(3);				//line options
	//fit->SetLineColor(kBlue);
	fit->SetLineStyle(2);				// 2=dashed, 3=dotted
	
	
	
	// sometimes depending on fucntion, fit might not converge
	// can set initial parameters (0=constant,1=mean,2=sigma) 	
 	fit->SetParameter(0, 40);
 	fit->SetParameter(1, 5);
 	fit->SetParameter(2, 1);
 	
 	//fit ->SetParameters(0,4,1); //alternative setting of parameters


	TCanvas *c1 = new TCanvas(); //creating the canvas
	hist->SetStats(0); //remove the statistics box - must be before the hist draw
	c1->SetTickx();
	c1->SetTicky();
	c1->SetGridx();
	c1->SetGridy();
	
	hist ->Draw(); //plotting the canvas
	hist->Fit("fit", "R"); // (fit type, R = region/range defined or Q=quiet, 0 = dont show fit)
	
	TLegend *leg = new TLegend(0.6,0.6,0.85,0.85);
	leg->SetBorderSize(0); // removing the border of legend with 0 border size
	leg->AddEntry(hist,"Measured Data", "f"); //(reference to the plot, name,flag of what to draw "l=line,p=point,f=filling"
	leg->AddEntry(fit, "Fit Funcation", "l");
	leg->Draw();
	
	double mean = fit->GetParameter(1);
	double sigma = fit->GetParameter(2);
	
	cout << mean/sigma << endl;
	
	

}
