//creating user defined functions


void tut13()
{
	TCanvas *c1 = new TCanvas();
	
	
	//straight line
	//TF1 *func = new TF1("func", "[0] + [1]*x", 0, 5); //setting name and function [function parameter number]

	//
	TF1 *func = new TF1("func", "exp(-[1]*x)*[0]*sin(x)", 10*TMath::Pi()); //setting name and function [function parameter number]
	
	func->SetTitle(""); 
	
	func->SetParameter(0, 1);
	func->SetParameter(1, 0.1);
	
	func->GetXaxis()->SetTitle("Test");
	func->GetYaxis()->SetTitle("Test");
	
	func->Draw();
	
	c1->Print("func.tex");

}
