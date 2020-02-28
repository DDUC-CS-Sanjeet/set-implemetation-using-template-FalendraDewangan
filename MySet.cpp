#include<iostream>
#include<math.h>
#include<string.h>


using namespace std;
template<typename T>
class MySet
{
    private:
    int n;
    T *p;
    public:
    MySet()
    {
        n=0;
    }

    MySet(int m)
    {
        n=m;
    	p= new T[n];
        input();
    }
    void set(int m)
    {
    	n=m;
    	p= new T[n];
	}
    void input()
    {
        
            cout<<"Enter element of your set : \n";
            for(int i =0;i<n;i++)
            {
                cin>>p[i];
            }
            removeduplicate();
            display();
    }
    void display()
    {
        cout<<"\nYour set is : {";
        for(int i =0;i<n;i++)
            {
                cout<<p[i];
                if(i!=n-1)
                    cout<<",";
            }
            cout<<"}"<<endl;
            cout<<"Cardinality of this set is : "<<this->n<<endl;
    }
    void removeduplicate()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;)
            {
                if(p[i]==p[j])
                {
                    for(int k=j;k<n-1;k++)
                    {
                        p[k]=p[k+1];
                    }
                    n--;
                }
                else
                {
                    j++;
                    
                }
                
            }
        }
    }

    void powerset() 
	{ 
    	int pow_set_size = pow(2,n); 
    	int counter, j; 

		cout<<"{ ";
	    for(counter = 0; counter < pow_set_size; counter++) 	
   		{ 
   			if(counter!=0)
   			cout<<",";
   			
   			cout<<"{ ";
    		for(j = 0; j < n; j++) 
    		{ 	
        		if(counter & (1 << j)) 
        		{
        			if(j!=0)
					cout<<" ";
					cout <<p[j];
				}
         	 
    		} 
    		cout<<"} ";
    	
    	}
		cout<<"}"; 
	} 
    
    MySet operator +(const MySet& b)
    {
        MySet temp;
        temp.set(this->n+b.n);
        int index=0;
        for(int i=0;i<this->n;i++)
        {
            temp.p[index++]=this->p[i];
        }
        for(int i=0;i<b.n;i++)
        {
            temp.p[index++]=b.p[i];
        }
        temp.removeduplicate();
        return temp;
    }
    MySet operator *(const MySet& b)
    {
        int index=0;
        for(int i=0;i<this->n;i++)
        {
            for(int j=0;j<b.n;j++)
            {
                if(this->p[i]==b.p[j])
                    index++;
            }           
        }
        MySet temp;
        temp.set(index);
        index=0;
        for(int i=0;i<this->n;i++)
        {
            for(int j=0;j<b.n;j++)
            {
                if(this->p[i]==b.p[j])
                    temp.p[index++]=b.p[j];
            }           
        }
        temp.removeduplicate();
        return temp;
    }

    MySet operator -(const MySet& b)
    {
    	bool flag=false;
        int index=0;
        for(int i=0;i<this->n;i++)
        {
        	flag=false;
            for(int j=0;j<b.n;j++)
            {
                if(this->p[i]==b.p[j])
                {
                	flag=true;
                	break;
				}
            }  
			if(flag)
				index++;        
        }
        
        MySet temp;
        temp.set(this->n-index);
        index=0;
        for(int i=0;i<this->n;i++)
        {
            
            for(int j=0;j<b.n;j++)
            {
            	flag=false;
                if(this->p[i]==b.p[j])
                    break;
                else
                {
                	flag =true;
				}
            }
            if(flag==true)
            {
            	temp.p[index++]=this->p[i];
			}    
        }
        temp.removeduplicate();
        return temp;
    }

    void operator =(const MySet& b)
    {
        b.n=this->n;
        for(int i=0;i<b.n;i++)
            b.p[i]=this->p[i];
    }

    bool operator ==(const MySet& b)
    {
        if(this->n!=b.n )
            return false;
        else
        {
            int j=0;
            bool flag=false;

            while(true)
            {
                for(int i=j;i<this->n;i++)
                {
                   if(this->p[i]==b.p[i])
                       {
                           flag=true;
                           break;
                       }
                       else
                       {
                           flag=false;
                       }
               }
               if(flag==false)
                    break;
               else if(flag && j==this->n-1)
               {
               	flag=false;
               	break;
			   }
                    
               j++;
            }
            if(!flag)
                return true;
            
            return false;
        }
    }
    
    MySet operator ^(MySet m)
    {
    		MySet temp;
    		temp.set(this->n);
    		temp.p=this->p;
            MySet w=(temp+m);
            MySet u=(temp*m);
            
    		return (w-u);    
	}
};

template<typename T>
void set(T a)
{	
    int choice,n,m;
    	cout<<"\t\t 1 for powerset of a set"<<endl;
        cout<<"\t\t 2 for union of two set"<<endl;
        cout<<"\t\t 3 for intersection of two set"<<endl;
        cout<<"\t\t 4 for difference between two set"<<endl;
        cout<<"\t\t 5 for equality of two set "<<endl;
        cout<<"\t\t 6 for symmetric difference "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        
    switch(choice)
    {
    	case 1:
        {
        	cout<<"Enter the size of set : ";
            cin>>n;
            MySet<T> b(n);
           	b.powerset();
        }
			break;
		
		case 2:
		{
			cout<<"Enter the size of first set : ";
            cin>>n;
            MySet<T> c(n);
            cout<<"\nEnter the size of second set : ";
            cin>>m;
            MySet<T> d(m);
           	MySet<T> x=c+d;
            x.display();
		}
        	break;
			
            
		case 3:
		{
			cout<<"Enter the size of first set : ";
            cin>>n;
            MySet<T> e(n);
            cout<<"\nEnter the size of second set : ";
            cin>>m;
            MySet<T> f(m);
            MySet<T> y=e*f;
            y.display();
		}
            break;
			
		case 4:
		{
			cout<<"Enter the size of first set : ";
            cin>>n;
            MySet<T> g(n);
            cout<<"\nEnter the size of second set : ";
            cin>>m;
            MySet<T> h(m);
            MySet<T> z=g-h;
            z.display();
		}
            break;
			
		case 5:
		{
			cout<<"Enter the size of first set : ";
            cin>>n;
            MySet<T> i(n);
            cout<<"\nEnter the size of second set : ";
            cin>>m;
            MySet<T> j(m);
			if(i==j)
				cout<<"two sets are equal "<<endl;
			else
				cout<<"two sets are not equal "<<endl;
		}	
            break;	
            
        case 6:
        {
        	cout<<"Enter the size of first set : ";
            cin>>n;
        	MySet<T> k(n);
            cout<<"\nEnter the size of second set : ";
            cin>>m;
            MySet<T> q(m);
            MySet<T> v=k^q;
            v.display();
		}
            break;
			
		default :
			cout<<"Invalid choice "<<endl;
	}
    
}

int main()
{	
    int choice2;
    double a=5.0;
    string g="null";
    char h='n';
    do 
     {
     	cout<<"\nEnter 1 for int elenemt in a set "<<endl;
        cout<<"enter 2 for character element in a set "<<endl;
        cout<<"enter 3 for double type element "<<endl;
        cout<<"enter 4 for string type element "<<endl;
        
        cout<<"Enter your type : ";
        cin>>choice2;
        switch(choice2)
        {
        	case 1:
        		set(choice2);
        		break;
        	case 2:
        		set(h);
        		break;
        	case 3:
        		set(a);
        		break;
        	case 4:
        		set(g);
        		break;
        		
        	default:
        			cout<<"Invalid choice"<<endl;
        		
		}
		
        cout<<"\nDo you want to continue y/n : ";
        cin>>h;
    
    }while(h=='y');
    return 0;
}

