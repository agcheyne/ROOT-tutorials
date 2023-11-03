//this program creates data with gaussian and fits


void tut6()
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

	TCanvas *c1 = new TCanvas(); //creating the canvas
 
	hist ->Draw(); //plotting the canvas

}
