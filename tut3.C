//this program learns how to input data into histogram


void tut3()
{
	TH1F *hist = new TH1F("hist", "Histogram", 6, 0, 6); //defining the historgram

	fstream file;
	file.open("data.txt", ios::in);

	double value;

	while(1)
	{
		file >> value;
		hist->Fill(value);
		if(file.eof()) break;
	}

	file.close();

	hist ->GetXaxis() ->SetTitle("Grade"); //setting axis
	hist ->GetYaxis() ->SetTitle("Entries"); 

	TCanvas *c1 = new TCanvas(); //creating the canvas
 
	hist ->Draw(); //plotting the canvas

}
