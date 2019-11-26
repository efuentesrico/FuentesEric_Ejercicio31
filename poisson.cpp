#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void poisson(string filename, int Nx);

int main(void)
{
    poisson("1.dat", 10);
    poisson("2.dat", 30);
    poisson("3.dat", 100);
}

void poisson(string filename, int Nx)
{
    
	// Declaración de variables y constantes.
    static double xmin = -1;
    static double xmax = 1;
    static double D = 1.0;
    static double s = 1.0;
	
    double dx = (xmax-xmin)/Nx;
    double dt = (dx*dx)/(2*D);
	
    double Psi_actualizado[Nx+2];
	double Psi[Nx+2];
    double dPsi_norm;
	dPsi_norm = 1;
	double dPsi_max;
	double Psi_max;
    
    
    //Condiciones iniciales.
	
    for(int j = 0; j < Nx+2; j++)
	{
            Psi[j]=0;
    }
	
	//Solución de Poisson.
	
    while (dPsi_norm>10e-5)
	{
        dPsi_max=0;
        Psi_max=0;
        
        for (int j = 1; j < Nx+1; j++)
		{
            Psi_actualizado[j]=(1.0/2)*Psi[j+1]+(1.0/2)*Psi[j-1]+s*dx*dx/(2*D);
			
            if ( abs(Psi_actualizado[j]-Psi[j])>dPsi_max )
			{
                dPsi_max=abs(Psi_actualizado[j]-Psi[j]);
            }
            if ( abs(Psi_actualizado[j])>Psi_max )
			{
                Psi_max=abs(Psi_actualizado[j]);
            }
            
        }
        dPsi_norm = dPsi_max/Psi_max;
        for(int j  = 1; j < Nx+1; j++){
            Psi[j]=Psi_actualizado[j];
            
        }
        
    }
    
	//Guarda el archivo.
	
    ofstream outfile;
    outfile.open(filename);
	
    for(int j  = 0; j < Nx+2; j++)
	{
        outfile << (j-1)*dx + xmin << ' ' <<  Psi[j] << endl;
    }
    
}
    
    
    