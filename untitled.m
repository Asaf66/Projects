clear all
clc
openExample('antenna/AntennaModelingAndAnalysisTutorialExample')
hx = helix('Radius',28e-3,'Width',1.2e-3,'Turns',4);

           
show(hx)
hx = helix('Radius',28e-3,'Width',1.2e-3,'Turns',4);
pattern(hx,1.8e9);
