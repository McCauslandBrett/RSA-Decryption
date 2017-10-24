#include <iostream>
#include<vector>
#include <math.h>
#include <fstream>

#include <sstream>
using namespace std;


void decryption(vector<int>& encrypted, vector<char> &decrypted, int d, int n);
template<typename Item_type>
void vector_print(vector<Item_type> &encrypted);
void driver_decyption();

template<typename Item_type>
void loadFromFile(vector<Item_type> &data);
void SaveToFile( string filename,const vector<char> Data, ofstream &myfile);
int simplifyMod(int root, int exponent, int modValue);


int main()
{
    //to solve a^b%c use simplifyMod(a,b,c)%c

    system("clear");
    driver_decyption();
    return 0;
}
void SaveToFile(string filename, const vector<char> Data, ofstream &myfile)
{
    myfile.open(filename.c_str());
    if(myfile.is_open())
       cout<<"open"<<endl;
        for(size_t i=0;i<Data.size();i++)
         {
            myfile<<Data[i];
            myfile<<" ";
         }

    myfile.close();
}
template<typename Item_type>
void loadFromFile(vector<Item_type> &data)
{
     ifstream myfile;
    //cout<<filename<<endl;
    myfile.open("input.txt");
    Item_type temp;
    if(myfile.is_open())
    {
      while (myfile>>temp)
         data.push_back(temp);
     myfile.close();
    }
    else
    {
        cout << "Unable to open file\n";
    }
   // cout<<"this is what i got:"<<endl;
   //vector_print(data);

}

void decryption(vector<int>& encrypted,vector<char>& decrypted,int d,int n)
{
    //+63
    int size=encrypted.size()-1;

    int p1;
    int p2;

        p1=2;
        cout<<"p2: ";
        p2=d/2;
        cout<<p2;


    long long int hold1,hold2,hold_result;
    char value;
    double c;
    for(int i=0;i<size;i++)
    {
        c=encrypted[i];
       hold1= ((int)(pow(c,p1)))%n;
       hold2=((int)(pow(c,p2)))%n;
       hold_result=((hold1*hold2)%n);
       cout<<"( hold: "<<hold_result<<")";
       value=(char)(hold_result+64);
       cout<<value<<" ";
       cout<<endl;
       decrypted.push_back(value);
    }

}

void driver_decyption()
{
      ofstream myfile;
       int d=6;
      int n=77;
       string s;
       string filename_input;
       string filename_output="output.txt";
       filename_input="a.txt";
       vector<char> message;
       vector<int> encryption;
       loadFromFile(encryption);
       decryption(encryption,message,d,n);
       SaveToFile(filename_output,message,myfile);



}
template<typename Item_type>
void vector_print(vector<Item_type>& encrypted)
{
    int size= encrypted.size()-1;
    for(int i=0;i<size;i++)
        cout<<encrypted[i]<<" ";
    cout<<endl;
}

int simplifyMod(int root, int exponent, int modValue)
{
    if(exponent > 1)
    {
        if(root < modValue)
        {
            if(exponent % 2 == 0)
            {
                return simplifyMod(pow(root, 2), exponent/2, modValue);
            }
            else if(exponent % 2 == 1)
            {
                return(simplifyMod(pow(root, 2), exponent/2, modValue)*simplifyMod(root, 1, modValue));
            }
        }
        else if(root >= modValue)
        {
            return simplifyMod(root%modValue, exponent, modValue);
        }
    }
    return root%modValue;
}
