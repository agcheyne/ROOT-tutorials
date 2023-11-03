//this program learns how to create a histogram and fills a couple of entries
//sets titles of x/y axis



void tut1()
{
TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100); //defining the historgram

hist ->Fill(10); //filling entriers
hist ->Fill(90);

hist ->GetXaxis() ->SetTitle("X Axis"); //setting axis
hist ->GetYaxis() ->SetTitle("Y Axis"); 

TCanvas *c1 = new TCanvas(); //creating the canvas
 
hist ->Draw(); //plotting the canvas

}
