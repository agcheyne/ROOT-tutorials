//drawing graphs and trying some marker size/style

void tut2()
{
	double x[5] = {1,2,3,4,5};
	double y[5] = {1,4,9,16,25};

	TGraph *gr = new TGraph(5, x, y); //creating the graph (number of entrier, x-array, y-array)

	TCanvas *c1 = new TCanvas();
	gr->SetMarkerStyle(4);
	gr->SetMarkerSize(2);

	gr->Draw("ALP"); // A for draw all, L for style (L=connected points, C=curve), P makes points,
}
