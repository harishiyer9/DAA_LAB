#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int Partition(int a[],int low,int high)
{
    int key = a[high];
    int i = low-1;
    for(int j=low; j<high; j++)
    {
        if(a[j]<key)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int key = Partition(a,low,high);
        QuickSort(a,low,key-1);
        QuickSort(a,key+1,high);
    }
}

int FindExt(string name)
{
    if(name.substr(name.find_last_of(".")) == ".txt" || name.substr(name.find_last_of(".")) == ".dat")
    {
        return 1;
    }
    return 0;
}

int main(int argc,char *argv[])
{
    char *foldername = argv[1];
    string folder = "";
    folder.append(foldername);
    string arg = "cd "+ folder + " && ls > input.txt";
    const char *arg1 = arg.c_str();
    system(arg1);


    int n;
    string name[6];
    ifstream infile;
    infile.open("Rfolder/input.txt");
    string fname;
    for(int j=0;j<6;j++)
    {
        infile>>name[j];
        //cout<<name[j]<<"\n";
    }

    for(int i=0;i<=5;i++)
    {
        fname = (name[i]);
        if(fname == "input.txt")
        {
            i++;
        }

        else if(fname.substr(fname.find_last_of(".")) == ".txt" || fname.substr(fname.find_last_of(".")) == ".dat")
        {
            ifstream in;
            string path = "Rfolder/"+fname;
	    	cout<<path<<"\n";
            const char * infile = path.c_str();
            in.open(infile);
            in >> n;
            cout<<n<<"\n";
            int *a = new int[n];
            for(int k=0; k<n; k++)
            {
                in>>a[k];
            }
            in.close();
            QuickSort(a,0,n);

            ofstream out;
			string outpath = "Rfolder/sorted_files/"+fname;
			const char * outfile = outpath.c_str();
            out.open(outfile);
            for(int k=0; k<n; k++)
            {
                out<<a[k]<<"\n";
            }
            out.close();
        }

    }
    return 0;
}
