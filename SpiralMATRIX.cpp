 vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int> v;
        int re=r,ce=c;
        int rs=0,cs=0;
        int t= 0;
        while(re>0 && ce>0)
        {
            for(int j=cs;j<ce;j++)
            {
                v.push_back(matrix[rs][j]);
                t++;
                 if(t==r*c)
                 return v;
            }
            rs++;
            for(int k=rs;k<re;k++)
            {
                v.push_back(matrix[k][ce-1]);
                t++;
                 if(t==r*c)
                 return v;
            }
            ce--;
            for(int i=ce-1;i>=cs;i--)
            {
                v.push_back(matrix[re-1][i]);
                t++;
                 if(t==r*c)
                 return v;
            }
            re--;
            for(int i=re-1;i>=rs;i--)
            {
                v.push_back(matrix[i][cs]);
                t++;
                 if(t==r*c)
                 return v;
            }
            cs++;
           
   

         
        }
        return v;
    }
