public String addBinary(String a, String b) {
      // Start typing your Java solution below
      // DO NOT write main() function
      StringBuffer a1 = (new StringBuffer(a).reverse());
      StringBuffer b1 = (new StringBuffer(b).reverse());
      int al = a1.length();
      int bl = b1.length();
      if(al<bl){
          StringBuffer k;
          k = a1;
          a1 = b1;
          b1 = k;
          int l = al;
          al = bl;
          bl = l;
      }
      int add = 0;
      StringBuffer c = new StringBuffer("");
      for(int i=0;i<al;i++){
          if(i>=bl || b1.charAt(i)==0){
              int k = a1.charAt(i)-'0'+add ;
              if(k==2){
                  k=0;
                  add = 1;
                  c.append(k);
              }else{
                  add = 0;
                  c.append(k);
              }
          }
          else{
              int k = a1.charAt(i)+b1.charAt(i)-'0'-'0'+add;
              if(k>=2){
                  k=k-2;
                  add = 1;
                  c.append(k);
              }else{
                  add = 0;
                  c.append(k);
              }
          }
      }
      if(add==1){
          c.append(1);
      }

      return c.reverse().toString();
  }
