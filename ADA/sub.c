int l=1,k=16;
       arr[0]=rand()%1000;
	          arr[1]=rand()%1000;
	          for(int j=2;j<i/2-1;j++)
	          {
	             if(j%2==0)
	             {  
	                arr[j]=rand()%1000+100+arr[j-2]+(k*l);
	                l=l*-1;
	              }
	              else
	              {
	               arr[j]=rand()%1000+100+arr[j-2]+(k)*l;
	               l=l*-1;
	               }
	          }     
	           for(int j=i/2,k=0;j<i;j++,k++)
	          {
	             
	                arr[j]=arr[k]+1;
	              
	               
	              
	          }
