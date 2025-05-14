//C++ program to write and read text in/from file.
#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
   fstream file;                //object of fstream class
    
    
   //opening file "groupA.txt" in out(write) mode
   file.open("groupA.txt",ios::out);
    
   if(!file)
   {
       cout<<"Error in creating file!!!"<<endl;
       return 0;
   }
    
   cout<<"File created successfully."<<endl;
   //write text into file
   file<<"hello, group members are : ragini, samruddhi, mugdha and megha.";
   //closing the file
   file.close();
    
   //again open file in read mode
   file.open("groupA.txt",ios::in);
    
   if(!file)
   {
       cout<<"Error in opening file!!!"<<endl;
       return 0;
   }   
    
   //read untill end of file is not found.
   char ch; //to read single character
   cout<<"File content: ";
    
   while(!file.eof())
   {
       file>>ch; //read single character from file
       cout<<ch;
   }
    
   file.close(); //close file
    
   return 0;
}
