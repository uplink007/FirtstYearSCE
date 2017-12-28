/% long
comment long
comment %/

procedure foo1(a, b, y : integer; c: char) return boolean
{
	var x, b : char;
	var res : boolean;

	b = '&';
	/% a = x; %/ 
	/% b = 8; %/
	a = (y * 7)/a-y;
	/% a = (y * 7)/b-y; %/
	/% a = (y * 7)/a-c; %/

	res = (b == c) && (y > a);
	/% res = (b == c) && (y + a); %/
	/% 3 + 6 = 9; %/
	/% ^x = 6; %/
	
    	return res ;
}


procedure fee1(i, j, k : integer) return integer
{
    var x, k : char;
    procedure fee2(l, m, n : integer) return boolean
    {
	var x, j, n: boolean;
	k = '@';
	i = l + l;
	/% i = j + 1; %/
	/% i = k + 1; %/
	if ((k == '*') || (x != false) && (l+m < i)){
		x = l < m;
	}
        return x;
    }
    {
	var k: boolean;
	k = fee2(5,i,j);
	/% x = fee2(5,i,j); %/
	/% k = fee2(5,i); %/
	/% k = fee2(5,x,j); %/
     }
    /% n = false; %/
    x = '#';	
    return 0;
}


procedure foo3(i, j, k : integer) return integer
{
    procedure square(t : integer) /% procedure declarations %/ return integer
    {
        var temp : integer;
        temp = t* t;
        return 0;
    }

    var total : integer;                       /% variable declarations %/
    var bool : boolean;
    bool = foo1(i,j,k,'^');
    /% j = foo2(); %/
    total = square(i+j+k);                    /% statements %/
    return 0;
}


procedure foo2() return integer
{
    var s1, s2: string[100];
    var i, j, cnt: integer;
    i=0;
    j=0;
    cnt = 1;
    while(i<|s1|){
	while(j<|s2|/2){
	    if (s1[i] == s2[j]){
		cnt = cnt*2;
	    }
	    j=j+1;
	}
	i=i+1;
    }
    return cnt;
}


procedure foo4() return integer
{
    {   
	var x : integer;
	var y : intptr;
	x = 5;
	y = &x;
	x = 6;
	if (&x == y && ^y == x){
		^y = 9;
	}
     	{
		var x : charptr;
		var y : string[10];
		var z : char;
		y = "foobar";
		x = &y[5];         
		z = ^(x - 5);       
		y = "barfoo"; 
   		 {
			/%var f : booleanptr; %/
			var x : char;
			var y : intptr;
			var z : charptr;
			var g : char;
			/% f = &(1+3);
			y = &x;             
			z = &(&g); %/
    		  }
	}
     }
    return 0;
}



procedure Main() return integer
{
    var a : integer;
    a = foo2();
    return 0;
}