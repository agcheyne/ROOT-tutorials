//adding a legend to our hist
//coords always from (0,0) to (1,1)


void tut8()
{
	TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 10); //defining the historgram (name, title, bins, min, max)
	
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

	hist ->GetXaxis() ->SetTitle("Distribution"); //setting axis
	hist ->GetYaxis() ->SetTitle("Entries"); 

	TF1 *fit = new TF1("fit", "gaus", 0, 10); // (name, fit, min,max of fit)
	
	
	// sometimes depending on fucntion, fit might not converge
	// can set initial parameters (0=constant,1=mean,2=sigma) 	
 	fit->SetParameter(0, 40);
 	fit->SetParameter(1, 5);
 	fit->SetParameter(2, 1);
 	
 	//fit ->SetParameters(0,4,1); //alternative setting of parameters


	TCanvas *c1 = new TCanvas(); //creating the canvas
	hist->SetStats(0); //remove the statistics box - must be before the hist draw
	hist ->Draw(); //plotting the canvas
	hist->Fit("fit", "R"); // (fit type, R = region/range defined or Q=quiet, 0 = dont show fit)
	
	TLegend *leg = new TLegend(0.6,0.7,0.9,0.9);
	leg->AddEntry(hist,"Measured Data", "l"); //(reference to the plot, name,flag of what to draw "l=line,p=point,f=filling"
	leg->AddEntry(fit, "Fit Funcation", "l");
	leg->Draw();
	
	double mean = fit->GetParameter(1);
	double sigma = fit->GetParameter(2);
	
	cout << mean/sigma << endl;
	
	

}
