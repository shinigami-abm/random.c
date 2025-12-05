import java.util.ArrayList;
import java.util.Scanner;

public class product{
   private String name;
   private String category;
   private String code_product;
   private double price;
   private int stock;

 public void set_name(String N){
	 this.name= N;
 }
 public void set_category(String cat){
	 this.category= cat;
 }
 public void set_code(String code){
	 this.code_product= code;
 }
 public void set_price(double P){
	 if(P < 0){
		 this.price= 0;
	 }
	 else{
             this.price= P;
	 }
 }
 public void set_stock(int S){
	 if(S<0){
		 System.out.println("the countety of the stock can not be negative");
	 }
	 else{
           this.stock= S;
	 }
 }
 public product(String N, String cat, String code, double P, int S){
	 this.set_name(N);
	 this.set_category(cat);
	 this.set_code(code);
	 this.set_price(P);
	 this.set_stock(S);
 }
 public String get_code(){
	 return this.code_product;
 }
 public String get_category(){
        return this.category;
 }
 public double get_price(){
         return this.price;
 }
 public int get_stock(){
      return this.stock;
 }
  public boolean sell(int Q){
	  if(Q<0){
		  System.out.println("this can not be real");
		return false;  
	  }
	  else if(this.stock < Q){
                  System.out.println("we dont have that much");
		 return false; 
	       }
	       else{
                  this.stock= this.stock-Q;
                 System.out.println("congrats");
		 return true;
	       }
  }
  public void buy(int Q){
	  if(Q<0){
		  System.out.println("the can not be real");
	  }
	  else{
            this.stock=this.stock+Q;
	    System.out.println("thank you for buying");
	    System.out.println("the new stock is" + this.stock);
	  }
  }
  public void print(){
      System.out.println("the name of the prudoct:" + this.name);
      System.out.println("the category of the product:"+ get_category());
      System.out.println("the code of the product:"+ get_code());
      System.out.println("the price:"+ get_price());
      System.out.println("the stock:"+ this.stock);
  }
  public static boolean search_code(String code){
   for(product p : products){
	   if(code == p.get_code()){
		   return true;
	   }
   }
    return false;
  }
  public static void Add_product(){
     System.out.println("give me the name of the product");
     String n= sc.nextLine();
     System.out.println("give me the category");
     String cat= sc.nextLine();
     System.out.println("give me it code");
     boolean ctr= true;
     while(ctr == true){
     String code= sc.nextLine();
      if(search_code(code) == true){
	     System.out.println("this code is all ready exiest redo it");
      }
      else{
	     ctr= false;
      }
     }
     System.out.println("give me the price");
     double pri=sc.nextInt();
     System.out.println("give me the quntity");
     int s= sc.nextInt();
      product p= new product(n, cat, code, pri, s);
      products.add(p);
  }
  public static int index(String code){
	  int c=0;
        for(product p: products){
		if(p.get_code().equals(code)){
                   return c;
		}
		else c++;
	}
  }
  public static void remove(){
	  System.out.println("give me the code of the product that you want to remove");
          String s= sc.nextLine();
	  if(search_code(code) == false){
		  System.out.println("this product is all ready removed or it does not existe");
		  return;
	  }
          products.remove(index(code));
	  System.out.println("the product has bean removed");
  }

  public static void menu(){
   System.out.println("1-Add product");
   System.out.println("2-delete product");
   System.out.println("3-Get all the products");
   System.out.println("4-Search for the product by category");
   System.out.println("5-Get the chipest product");
   System.out.println("6-register a purchase");
   System.out.println("7-Register a sale");
   System.out.println("0-Quite");
  }
  public static void All(){
     for(product p: products){
	     p.print();
     }
  }
  public static void search_by_cat(){
	  System.out.println("give me the category");
	String cat= sc.nextLine();
	  for(product p: products){
		  if(p.get_category().equals(cat)){
			  p.print();
		  }
	  }
  }
  public static void cheapst(){
	  double min;
	  int index=0;
	  int c=0;
        for(product p: products){
		if(min < p.get_price()){
			min= p.get_price();
			index=c;
		}
		c++;
	}
	System.out.println("the cheapst product is:");
        products.get(index).print();
  }
  public static void register_purchase_and_sale(int i){
	  System.out.println("give me the code of the product");
	  boolean ctr=true;
	 while(ctr == true){ 
	  String s= sc.nextLine();
	  if(search_code(code) == false){
		  System.out.println("there is no product such that");
		  System.out.println("redo it");
	  }
	  else if(i == 1){
		  System.out.println("give me how much you want to buy");
		  int q=sc.nextInt();
		  for(product p: products){
			  if(p.get_code().equals(code)){
				  p.buy(q);
				  System.out.println("the new stock is:"+ p.get_stock());
			        return;	  
			  }
		  }
	  }
	  else if(i == 2){
           System.out.println("give me how much you want to sell");
	   int q=sc.nextInt();
	   for(product p: products){
		   if(p.get_code().equals(code)){
			 if(p.sell(q) == true){
                           System.out.println("the new stock is:" + p.get_stock());
			 }
                       return;
		   }

	   }
	  }
  }
}
 public static void main(String[] args){
	 static ArrayList<product> products= new ArrayList<>();
	 static Scanner sc= new Scanner(System.in);
    while(true){
	    menu();
	   System.out.println("Give me your choice"); 
	   int choice=sc.nextInt();

	    switch(choice){
               case 1:
                  Add_product();
                   break;
	       case 2:
		   remove();
                   break;
	       case 3:
		   All();
                   break;
	       case 4:
                   search_by_cat();
                   break;
	       case 5:
		   cheapst();
                   break;
	       case 6:
                     register_purchase_and_sale(1);
                   break;
	       case 7:
		     register_purchase_and_sale(2);
                   break;
	       case 0:
	          System.out.println("thank you");
		  return;
                   break;
	       defult:
		   System.out.println("wrong input");
                   break;
	    }
    }	 
 }
