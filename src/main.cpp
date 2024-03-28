#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Employee
{
	public:
		string mEmpid;
		string mName;
		string mSalary;
		
		public: 
        //construtor declared with parameter
		Employee(string empid="",string name="", string salary="") : mEmpid(empid), mName(name),mSalary(salary){
			
		}
		// In order to work with serialization we need to use two concepts...
        // overloading == operator in order to work with serilazation
		bool operator==(const Employee& obj){
			return (mEmpid==obj.mEmpid)&&(mName==obj.mName)&&(mSalary==obj.mSalary);
		}
		//friend function for  filwritinge using fstream
		friend ostream& operator<<(ostream& out,const Employee& obj)
        {
			out<<obj.mEmpid<<" "<<obj.mName<<" "<<obj.mSalary<<endl;
            return out;
		}

        // friend finction to reading files
        friend istream& operator>>(istream& in, Employee& obj)
        {
            in >> obj.mEmpid;
            in >> obj.mName;
            in >> obj.mSalary;
            return in;
        }
};

class EmployeeData{
	
		public:

        //Addemployee function to add employee details and stored the in the file
		void Addemployee()
        {
		string empid,name,salary;

		cout << "Enter EMployee id : ";
		cin >> empid;
		cout << "Enter Employee Name : ";
		cin >> name;
		cout << "Enter Employee Salary : ";
		cin >> salary;
		Employee emp(empid,name,salary);
		ofstream output("Employee1.txt",ios::app);   //using ofstream to write file 
		output<<emp;
		output.close(); //file closing 
		cout<<"Employee "<<empid<<" is stored successfully"<<endl;
		}

		void Displayemployee()
        {

            //Display information of employee from the file 
            cout<<"EmpId\tName\tSalary"<<endl;
            Employee e;
            ifstream in("Employee1.txt",ios::in);
            while(in)   
            {
                in>>e;
                cout<<e.mEmpid<<"\t" <<e.mName<<"\t"<<e.mSalary<<endl;                                           
            }
            in.close();//file closed
        }

		double generatePayslip()
        {

            //generating payslip 
            int month;
            string id;
            double amt;
            cout <<"ENter month(in digits)";
            cin >> month;
             cout <<"Enter Employee id : "<<endl;
             cin >> id;

            int NoofDays;;
                cout<<"\nEnter No of present days: ";
                cin>>NoofDays;
            Employee e;
            ifstream in("Employee1.txt",ios::in);    //writing data from file
            while(in)
            {
                in>>e;
              if(id==e.mEmpid)  //checking employee id with file data 
              {

                double salary= stod(e.mSalary);
                
                switch (month)
                {
                    case 1:
                       amt= CalculateSalary(salary,NoofDays,31);
                       return amt;
                break;
                        
                    case 2:
                      amt= CalculateSalary(salary,NoofDays,28);
                        return amt;
                      break;
                    case 3:
                       amt= CalculateSalary(salary,NoofDays,31);
                       return amt;
                      break;
                    case 4:
                       amt= CalculateSalary(salary,NoofDays,30);
                       return amt;
                    break;

                    case 5:
                       amt= CalculateSalary(salary,NoofDays,31);
                       return amt;
                    break;

                    case 6:
                       amt= CalculateSalary(salary,NoofDays,30);
                       return amt;
                    break;

                    case 7:
                       amt= CalculateSalary(salary,NoofDays,31);
                       return amt;
                    break;

                    case 8:
                       amt= CalculateSalary(salary,NoofDays,31);
                       return amt;
                    break;

                    case 9:
                       amt= CalculateSalary(salary,NoofDays,30);
                       return amt;
                    break;

                    case 10:
                        amt= CalculateSalary(salary,NoofDays,31);
                        return amt;
                    break;

                    case 11:
                       amt= CalculateSalary(salary,NoofDays,30);
                       return amt;
                    break;

                    case 12:
                        amt=CalculateSalary(salary,NoofDays,31);
                        return amt;
                    break;
                    
                    default:
                    break;
                }

              }
              else{

              }                                         
            }
            in.close();
            return amt;
		}
        double CalculateSalary(double salary,int present,int totaldays){
            if(present>totaldays){
                cout<<"Present days connot be greater than total days"<<endl;
            }
            double perday= salary/totaldays;
            double amt=perday*present;
            cout<<"Payable amount is "<<amt;
            return amt;
        }
        void createPayslip(){
           Employee e;
           string id;
           cout <<"Enter Employee id : "<<endl;
             cin >> id;
                         ifstream in("Employee1.txt",ios::in);    //writing data from file

             while(in)
            {
                in>>e;
              if(id==e.mEmpid)  //checking employee id with file data 
              {

              

                    double amt=generatePayslip();
                    	
                    	ofstream output("Pay slip.doc");   //using ofstream to write file 
        cout<<"\n--------------------------- Eicher Company---------------------------"<<endl;
                        output<<"Employee ID : "<<e.mEmpid<<endl;
                        output<<"Name of the employee : "<<e.mName<<endl;
                        output<<"Basic Salary of the Employee : "<<e.mSalary<<endl;
                        output<<"AMount Payable :"<<amt<<endl;
                }                                          
            }   
        } 
};

int main()
{
	
    int choice=0;
    EmployeeData emp;
     do
     {
        cout<<"\n--------------------------- Eicher Company---------------------------"<<endl;
        cout<<"\n1.Add Employee."<<endl;
        cout<<"\n2.Display Employee."<<endl;
        cout<<"\n3.Check Employee payable salary  ."<<endl;
        cout<<"\n4.Generate Pay slip"<<endl;
        cout<<"\n5.Exit."<<endl;

        cout<<"Enter an Option : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            emp.Addemployee();
            break;
        case 2:
        	emp.Displayemployee();
	           break;

        case 3:
			emp.generatePayslip();
            break;
        case 4:
        	emp.createPayslip();
        	break;
            case 5:
            cout<<"Application closed . Thanks"<<endl;
            break;
        default :
			cout<<"Invalid Choice"<<endl;
            break;
        }
    } while (choice != 6);
    
    return 0;
}
