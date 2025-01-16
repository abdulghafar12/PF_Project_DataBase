
#include <iostream>
#include<fstream>
#include<string>
using namespace std; 


void Save_Student_data()
{
    ifstream Myfile("fileName.txt");
    ofstream save_file("save.txt");
    if(!Myfile)
    {
        cout<<"File not found.\n";
        return;
    }
    else{
    string line;
    while(getline(Myfile, line))
    {
        save_file<<line<<endl;
    }
    }
    Myfile.close();
    save_file.close();
    cout<<"Data saved successfully.\n";
}

void delete_data()
{
    int choice;
    cout<<"\nDelete data by \"Roll Number\"  enter the :  1\nDelete data by \"Name\" enter the : 2\n";
    cin>>choice;
    ifstream Myfile("fileName.txt");
    ofstream delt_File("delte.txt");
    bool found = false;
    if(!Myfile)
    {
        cout<<"File not found.\n";
        return;
    }
    else{
    string line;
    string search_data;
    if(choice == 1)
    {
        int Rol_no;
        cout<<"Enter the Student Roll Number you want to delete:  "<<endl;
        cin>>Rol_no;
        cout<<endl;
        search_data = to_string(Rol_no);
    }
    else if(choice == 2)
    {
        cout<<"Enter the Student Name you want to delete:  "<<endl;
        cin.ignore();
        getline(cin, search_data);
    }
    while(getline(Myfile, line))
    {
        if(line.find(search_data) == string::npos)
        {
            delt_File<<line<<endl;
        }
        else
        {
            found = true;
        }
    }
    }
    Myfile.close();
    delt_File.close();
    if(found)
    {
        remove("fileName.txt");
        remove("fileName.txt");
        rename("delte.txt", "fileName.txt");
        cout<<"\nData deleted successfully.\n";
    }
    else
    {
        remove("delte.txt");
        cout<<"Data not found.\n";
    }
}
void Display_all_Student()
{
    ifstream Myfile("fileName.txt");
    string line;
    //cout<<"Rol_No|Name|Gendr|Age|DOB|Admis_Yr|Semestr|Phon_No|Fat_Nam|Fat_Occupa|Address|Fee|Fe_Paid|FeDue|Fe_Concess|Fe_Status|Fe_Conce_Stat|CGPA|Departm|Specialty|Uni|Campus||City\n"<<endl;
    //cout<<"----------------=======-------------------------========--------------------========--------------------------========------------------------------========------------------------\n";
    cout<<endl;
    cout<<"\n \t === \"The Admitted Student are:\" === :\n";
    while(getline(Myfile, line))
    {
        cout<<endl;
        cout<<line<<endl;
    }
    Myfile.close();
}
struct NewStudent
{
    int rollNo,age,dob,admission_year,semester,contact,father_contact,fee,fee_paid,fee_due,fee_concession;
    string fee_concession_status,gender,fee_status;
    float cgpa;
    string department,name,address,father_name,father_occupation;
    string specialization;
    string University;
    string campus;
    string city;
    };
void add_newStudent()
{
    NewStudent u[10];
    for(int i = 0; i < 1; ++i)
    {
        cout<<"Enter the New Student Details: \n";
        cout<<"\n----------============================------------------==============================---------------\n";
        cout<<"Enter New Student Name: ";
        cin.ignore();
        getline(cin,u[i].name);
        cout<<"Enter  New Student Roll No: ";
        cin>>u[i].rollNo;
        cout<<"Enter New Student Gender: ";
        cin.ignore();
        getline(cin,u[i].gender);
        cout<<"Enter New Student Age: ";
        cin>>u[i].age;
        cout<<"Enter New Student Date of Birth: ";
        cin>>u[i].dob;
        cout<<"Enter New Student Admission Year: ";
        cin>>u[i].admission_year;
        cout<<"Enter New Student Semester: ";
        cin>>u[i].semester;
        cout<<"Enter New Student Contact No: ";
        cin>>u[i].contact;
        cout<<"Enter New Student Father_Name: ";
        cin.ignore();
        getline(cin,u[i].father_name);
        cout<<"Enter New Student Father_Occupation: ";
        getline(cin,u[i].father_occupation);
        cout<<"Enter New Student Address: ";
        getline(cin,u[i].address);
        cout<<"Enter New Student Fee: ";
        cin>>u[i].fee;
        cout<<"Enter New Student Fee Paid: ";
        cin>>u[i].fee_paid;
        cout<<"Enter New Student Fee Due: ";
        cin>>u[i].fee_due;
        cout<<"Enter New Student Fee Concession: ";
        cin>>u[i].fee_concession;
        cout<<"Enter New Student Fee Concession Status: ";
        getline(cin,u[i].fee_concession_status);
        cout<<"Enter NewStudent CGPA: ";
        cin>>u[i].cgpa;
        cout<<"Enter New Student Department: ";
        cin.ignore();
        getline(cin,u[i].department);
        cout<<"Enter New Student Specialization: ";
        getline(cin,u[i].specialization);
        cout<<"Enter New Student University name : ";
        getline(cin,u[i].University);
        cout<<"Enter New Student Campus: ";
        getline(cin,u[i].campus);
        cout<<"Enter New Student City: ";
        getline(cin,u[i].city);
        cout<<endl;
    }
    ofstream Myfile("fileName.txt" , ios::app);
    for(int i = 0; i < 1; ++i)
    {
    Myfile<<u[i].rollNo<<"    "<<u[i].name<<"   "<<u[i].gender<<"  "<<u[i].age<<"   "<<u[i].dob<<"  "<<u[i].admission_year<<"  "<<u[i].semester<<"    "<<u[i].contact<<"  "<<u[i].father_name<<"   "<<u[i].father_occupation<<"  "<<u[i].address<<"   "<<u[i].fee<<"  "<<u[i].fee_paid<<"  "<<u[i].fee_due<<"   "<<u[i].fee_concession<<"  "<<u[i].fee_status<<"   "<<u[i].fee_concession_status<<"   "<<u[i].cgpa<<"  "<<u[i].department<<"  "<<u[i].specialization<<"   "<<u[i].University<<"   "<<u[i].campus<<"  "<<u[i].city<<endl;
    }
    Myfile.close();
    cout<<"Data Added Successfully\n";
}
void Search_Student()
{
    int RoL_No;
    cout<<"Enter the Student Roll No: ";
    cin>>RoL_No;
    cout<<endl;
    bool found = false;
    ifstream Myfile("fileName.txt");
    string line;
    while(getline(Myfile, line))
    {
        if(line.find(to_string(RoL_No)) != string::npos)
        {
            
            cout<<"Rol_No|Name|Gendr|Age|DOB|Admis_Yr|Semestr|Phon_No|Fat_Nam|Fat_Occupa|Address|Fee|Fe_Paid|FeDue|Fe_Concess|Fe_Status|Fe_Conce_Stat|CGPA|Departm|Specialty|Uni|Campus||City\n"<<endl;
            cout<<"=================^^^^^^=================^^^^^^^^================^^^^^^================^^^^^^=================^^^^^^================^^^^^^===============^^^^^^===================\n";
            cout<<line<<endl;
            found = true;
            break;
        }
    }
    Myfile.close();
    if(!found)
    {
        cout<<"Sorry Data Not Found\n";
    }
}
struct Student_detail
{
   int rollNo,age,dob,admission_year,semester,contact,father_contact,fee,fee_paid,fee_due,fee_concession;
    string fee_concession_status,gender,fee_status;
    float cgpa;
    string department,name,address,father_name,father_occupation;
    string specialization;
    string University;
    string campus;
    string city;
};
void Enter_Student_data()
{
     Student_detail u[10];
     ofstream Myfile("fileName.txt" ,ios::app);
     for(int i = 0; i<1; ++i)
    {
        cout<<"Enter the Student Details: \n";
        cout<<"\n----------============================------------------==============================---------------\n";
        cout<<"Enter Student Name: ";
        cin.ignore();
        getline(cin,u[i].name);
        cout<<"Enter Student Roll No: ";
        cin>>u[i].rollNo;
        cout<<"Enter Student Gender: ";
        cin.ignore();
        getline(cin,u[i].gender);
        cout<<"Enter Student Age: ";
        cin>>u[i].age;
        cout<<"Enter Student Date of Birth: ";
        cin>>u[i].dob;
        cout<<"Enter Student Admission Year: ";
        cin>>u[i].admission_year;
        cout<<"Enter Student Semester: ";
        cin>>u[i].semester;
        cout<<"Enter Student Contact No: ";
        cin>>u[i].contact;
        cout<<"Enter Student Father_Name: ";
        cin.ignore();
        getline(cin,u[i].father_name);
        cout<<"Enter Student Father_Occupation: ";
        getline(cin,u[i].father_occupation);
        cout<<"Enter Student Address: ";
        getline(cin,u[i].address);
        cout<<"Enter Student Fee: ";
        cin>>u[i].fee;
        cout<<"Enter Student Fee Paid: ";
        cin>>u[i].fee_paid;
        cout<<"Enter Student Fee Due: ";
        cin>>u[i].fee_due;
        cout<<"Enter Student Fee Concession: ";
        cin>>u[i].fee_concession;
        cout<<"Enter Student Fee Concession Status: ";
        getline(cin,u[i].fee_concession_status);
        cout<<"Enter Student CGPA: ";
        cin>>u[i].cgpa;
        cout<<"Enter Student Department: ";
        cin.ignore();
        getline(cin,u[i].department);
        cout<<"Enter Student Specialization: ";
        getline(cin,u[i].specialization);
        cout<<"Enter Student University name : ";
        getline(cin,u[i].University);
        cout<<"Enter Student Campus: ";
        getline(cin,u[i].campus);
        cout<<"Enter Student City: ";
        getline(cin,u[i].city);
        cout<<endl;
        Myfile<<"Rol_No|Name|Gendr|Age|DOB|Admis_Year|Semestr|Phon_No|Father_Nam|Father_Occupa|Address|Fee|Fe_Paid|FeDue|Fe_Concession|Fe_Status|Fe_Concesi_Status|CGPA|Departm|Specialty|Uni|Campus||City\n"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
      
        Myfile<<u[i].rollNo<<"    "<<u[i].name<<"  "<<u[i].gender<<"   "<<u[i].age<<"   "<<u[i].dob<<"  "<<u[i].admission_year<<"   "<<u[i].semester<<"    "<<u[i].contact<<"  "<<u[i].father_name<<" "<<u[i].father_occupation<<"  "<<u[i].address<<" "<<u[i].fee<<"  "<<u[i].fee_paid<<"  "<<u[i].fee_due<<"  "<<u[i].fee_concession<<"  "<<u[i].fee_status<<"  "<<u[i].fee_concession_status<<"  "<<u[i].cgpa<<"  "<<u[i].department<<"  "<<u[i].specialization<<"  "<<u[i].University<<"  "<<u[i].campus<<"  "<<u[i].city<<endl;
        cout<<"\nThe data has been stored successfully.";
        cout<<endl;
        Myfile.close();
    }
}
int main()
{  
    int choic;
do
{
    cout<<"\n\n\t\t\t\t\t~|:= \" Welcome To Student DataBase \" =:|~ \n";
    cout<<"\n\t\t\t\t\t\t~|:= \" What do You Want \" =:|~ \n";
    cout<<"\n---======||=====||=====||======||=======||========||========||=====---\n";
    cout<<endl;
    cout<<"Enter the Data||View Data||Search Student||Add New Data||Save the Data||Delete Data||Exit from the DataBase\n"<<endl;
    cout<<endl;
    cout<<"-------1------------2------------3---------------4-------------5-------------6-----------------7------------\n";
    cout<<"\n---===========  =======  ======  =======  ====   =======   =====  =======  ====   ======   =====   ========   =======\n\n"<<endl;
    cin>>choic;
    cout<<"\n\t\t\tYou have selected Choice: "<<choic<<endl;
    switch (choic)
    {
    case 1 :
        Enter_Student_data();   
        break;
    case 2 :
      Display_all_Student();
        break;
    case 3 :
      Search_Student();
        break;
    case 4 :
       add_newStudent();
        break;
    case 5 :
       Save_Student_data();
        break;
    case 6 :
        delete_data();
        break;
    case 7 :
    cout<<"\n\n\t\t\t\t\t\"You have selected to Exit from the System.\"\n";
    exit(0);
        break;
    default:
        cout<<"Invalid Choice.\n";
        break;
    }
    }while(choic != 7);

    return 0;
}