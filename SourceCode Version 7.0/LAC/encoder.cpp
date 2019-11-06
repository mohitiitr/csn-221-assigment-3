#include "../data/encoder.h" 
#include "../data/Read.h" 
using namespace std; 

void lac_encoder(string filename)
{
    ifstream file("../data/"+filename+".txt");
    ofstream file_encoded(filename+"_encoded.txt");
    string s;
    int data;
    int type;
    int index;
    while( getline(file,s))
    {
        type=0;
        data=read(type,s);
        if(type==2)
        {
            index=write_txt_data(data);
            s=reform(s,index);
        }              
        file_encoded<<s<<"\n";   
    }       
    file.close();
    file_encoded.close(); 
}

int main() 
{ 
    ofstream file("immediate_data.txt");
    file.close();
    lac_encoder("file1");
    return 0; 
} 