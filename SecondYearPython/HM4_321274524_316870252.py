'''
@Author 1 - Sergey shevchuk ID 321274524
@Athor 2 - Timor Satarov ID 316870252
@Work - HM4_321274524_316870252
'''

from math import sqrt
import math,random
'''Targil 1 alef'''
from ast import walk
print("****************Targil 1 alef*******************")
def make_instance(cls):
        """Return a new object instance, which is a dispatch dictionary."""
        attributes = {}
        def get_value(name):
            if name in attributes:
                return attributes[name]
            else:
                value = cls['get'](name)
            return bind_method(value, instance)
        def set_value(name, value):
            if callable(value):
                cls['set'](name,value)
            else:
                attributes[name]=value
        instance = {'get': get_value, 'set': set_value}
        return instance
    
def bind_method(value, instance):
        """Return a bound method if value is callable, or value otherwise."""
        if callable(value):
            def method(*args):
                return value(instance, *args)
            return method
        else:
            return value
        
def make_class(attributes, base_class=None):
        """Return a new class, which is a dispatch dictionary."""
        def get_value(name):
            if name in attributes:
                return attributes[name]
            elif base_class is not None:
                return base_class['get'](name)
        def set_value(name, value):
            attributes[name] = value
        def new(*args):
                return init_instance(cls, *args)
        cls = {'get': get_value, 'set': set_value, 'new': new}
        return cls
    
def init_instance(cls, *args):
        """Return a new object with type cls, initialized with args."""
        instance = make_instance(cls)
        init = cls['get']('__init__')
        if init:
            init(instance, *args)
        return instance
    
def make_Point_class():
    """return point class"""
    count=0
    def __init__(self,x=0,y=0):
        nonlocal count
        self['set']('x',x)
        self['set']('y',y)
        count+=1
    def strr(self):
        return '(%d,%d)' % (self['get']('x'), self['get']('y'))
    def counter(self=None):
        return count
    def prt(self):
        print(self['get']('str')())
    def shift(self, number):
        self['set']('x',self['get']('x')+ number)
        self['set']('y',self['get']('y')+ number)
    def eq(self, other):
        return self['get']('x') == other['get']('x')  and  self['get']('y') == other['get']('y')
    def getX(self):
        return self['get']('x')
    def getY(self):
        return self['get']('y')
    def setX(self,x):
        self['set']('x',x)
    def setY(self,y):
        self['set']('y',y)
    def distance(self,other):
        return (((self['get']('x')-other['get']('x'))**2)+((self['get']('y')-other['get']('y'))**2))**0.5
    return make_class({'__init__':__init__,'str':strr,'print':prt,'shift':shift,'==':eq,'counter':counter,'setX':setX,'setY':setY,'getX':getX,'getY':getY,'distance':distance})

print("***PointClassDriver***")
print('>>>Point = make_Point_class()')
Point = make_Point_class()
print('>>>p1 = Point["new"](4,5)')
p1 = Point["new"](4,5)
print(">>>p1['get']('str')()")
print(p1['get']('str')())
print("driver=(4,5)")
print("p1['get']('setY')(3)")
p1['get']('setY')(3)
print(">>>p1['get']('str')()")
print(p1['get']('str')())
print("driver=(4,3)")
print(">>>p2 = Point['new']()")
p2 = Point['new']()
print(">>>p2['get']('str')()")
print(p2['get']('str')())
print("driver=(0,0)")
print(">>>p1['get']('distance')(p2)")
print(p1['get']('distance')(p2))
print("driver=5")

def make_Line_class():
    count=0
    def __init__(self,p1=Point['new'](),p2=Point['new']()):
        nonlocal count
        self['set']('p1',p1)
        self['set']('p2',p2)
        count+=1
    def initAB(self):
        if(self['get']('p1')['get']('==')(self['get']('p2'))):
            a=None
            b=None
        elif self['get']('p1')['get']('getY')()==self['get']('p2')['get']('getY')():
            a=0
            b=self['get']('p1')['get']('getY')()
        elif self['get']('p1')['get']('getX')()==self['get']('p2')['get']('getX')():
            a=None
            b=None
        else:
            a=(self['get']('p1')['get']('getY')()-self['get']('p2')['get']('getY')())/(self['get']('p1')['get']('getX')()-self['get']('p2')['get']('getX')())
            b= self['get']('p1')['get']('getY')()-a*self['get']('p1')['get']('getX')()  
        return a,b                                       
    def strr(self):
        a,b=initAB(self)
        if(a==None and b==None):
            if(self['get']('p1')['get']('getY')()!=self['get']('p2')['get']('getY')()):
                return 'x=%d'%(self['get']('p1')['get']('getX')())
            else:
                return 'Not a line'
        if(a):
            return 'y=%0.2fx+%0.2f'%(a,b)
        else:
            return 'y=%0.2f'%(b)
    def setPoint(self,i,x,y):
        if(i==1):
            self['get']('p1')['get']('setX')(x)
            self['get']('p1')['get']('setY')(y)   
        elif(i==2):
            self['get']('p2')['get']('setX')(x)
            self['get']('p2')['get']('setY')(y) 
        else:
            print(str(i)+'is wrong index,there is only 1-for first point and 2-for the second point')
    def getPoint(self,i):
        if(i==1):
            return Point['new'](self['get']('p1')['get']('getX')(),self['get']('p1')['get']('getY')())
        elif(i==2):
            return Point['new'](self['get']('p2')['get']('getX')(),self['get']('p2')['get']('getY')())
        else:
            print(str(i)+'is wrong index,there is only 1-for first point and 2-for the second point')   
    def isOnLine(self,otherP):
        a,b=initAB(self)
        if(a!=None):
            if (otherP['get']('getY')()-a*otherP['get']('getX')()-b) :
                return False
            return True
        return False
    return make_class({'__init__':__init__,'str':strr,'isOnLine':isOnLine,'setPoint':setPoint,'getPoint':getPoint,'initAB':initAB})

print("***LineClassDriver***")        
print(">>>Line = make_Line_class()")
Line = make_Line_class()
print(">>>l1 = Line['new']()")
l1 = Line["new"]()
print(">>>l1['get']('setPoint')(1,2,3)")
l1['get']("setPoint")(1,2,3)
print(">>>l1['get']('setPoint')(2,8,6)")
l1['get']("setPoint")(2,8,6)
print(">>>l1['get']('str')()")
print(l1['get']("str")())
print("driver=y = 0.5x + 2")
print(">>>p = l1['get']('getPoint')(1)")
p = l1['get']("getPoint")(1)
print(">>>l1['get']('isOnLine')(p)")
print(l1['get']("isOnLine")(p))
print("driver=True")

def make_Estimated_Line_class():
    count=0
    def __init__(self):
        nonlocal count
        self['set']('distance',0)
        Line['get']('__init__')(self)
    def getDistance(self):
        return self['get']('distance')
    def setDistance(self,d):
        self['set']('distance',d)
    def strr(self):
        return Line['get']('str')(self)+' ; '+'%d'%(self['get']('getDistance')())
    def isOnLine(self,p):
        a,b=self['get']('initAB')()
        if(a!=None):
            if self['get']('distance')>=abs((a*p['get']('getX')()-p['get']('getY')()+b)/sqrt(a**2+1)):
                return True
            return False
        return False
    return make_class({'__init__':__init__,'getDistance':getDistance,'setDistance':setDistance,'str':strr,'isOnLine':isOnLine},Line)

print("***EstimatedLineClassDriver***")
print(">>>E_Line = make_Estimated_Line_class()")
E_Line = make_Estimated_Line_class()
print(">>>el = E_Line['new']()")
el = E_Line["new"]()
print(">>>el['get']('setPoint')(1,1,6)")
el['get']("setPoint")(1,1,6)
print(">>>el['get']('setPoint')(2,3,2)")
el['get']("setPoint")(2,3,2)
print(">>>el['get']('setDistance')(5)")
el['get']("setDistance")(5)
print(">>>el['get']('str')()")
print(el['get']("str")())
print("driver=y = -2x + 8 ; 5")
print(">>>p = Point['new']()")
p = Point["new"]()
print(">>>el['get']('isOnLine')(p)")
print(el['get']("isOnLine")(p))
print("driver=True")
print(">>>el['get']('setDistance')(3)")
el['get']("setDistance")(3)
print(">>>el['get']('isOnLine')(p)")
print(el['get']("isOnLine")(p))
print("driver=False")
print("*******************Targil 1 gimel*******************")
print(">>>el['set']('value','Not a function')")
el['set']('value','Not a function')
print(">>>el['get']('value')")
print(el['get']('value'))
print("driver=Not a function")
print(">>>E_Line['get']('value')")
print(E_Line['get']('value'))
print("driver=None")
print(">>>el['set']('function',lambda self,x:x(self['get']('str')()))")
el['set']('function',lambda self,x:x(self['get']('str')()))
print(">>>el['get']('function')(print)")
el['get']('function')(print)
print("driver= y=-2.00x+8.00 ; 3")
print(">>>E_Line['get']('function')(el,print)")
E_Line['get']('function')(el,print)
print("driver= y=-2.00x+8.00 ; 3")
print(">>>el2=E_Line['new']()")
el2=E_Line['new']()
print(">>>el['get']('setPoint')(1,5,7)")
el['get']("setPoint")(1,5,7)
print("el['get']('setPoint')(2,0,0)")
el['get']("setPoint")(2,0,0)
print(">>>el2['get']('function')(print)")
el2['get']('function')(print)
print("driver= y=1.40x+0.00 ; 0")

'''
print("*******************Targil 1 bet:(Need to change docstrings becase of the same names of classes!!!*******************")

def make_pair(x,y):
    def dispatch(i,v=None):
        nonlocal x
        nonlocal y
        if(v==None):
            if i==0:
                return x
            if i==1 :
                return y
            return None
        else:
            if i==0:
                x=v
            if i==1 :
                y=v
    return dispatch

def make_mutable_rlist():
        """Return a functional implementation of a mutable recursive list."""
        contents = empty_rlist
        def strr():
            mrlist=contents
            k="["
            while(mrlist!=None):
                k+='('+str(first(mrlist)(0))+','+str(first(mrlist)(1))+')'
                if(rest(mrlist)!=None):
                    k+=','
                mrlist=rest(mrlist)
            k+=']'
            return k
        
        def dispatch(message, value=None):
            nonlocal contents
            if message == 'len':
                return len_rlist(contents)
            elif message == 'getitem':
                return getitem_rlist(contents, value)
            elif message == 'push_first':
                contents = make_rlist(value, contents)
            elif message == 'pop_first':
                f = first(contents)
                contents = rest(contents)
                return f
            elif message == 'str':
                return strr()
        return dispatch
    
empty_rlist = None
def make_rlist(first, rest):
    """Make a recursive list from its first element and the rest."""
    return make_pair(first, rest)
def first(s):
    """Return the first element of a recursive list s."""
    return s(0)
             
def rest(s):
    """Return the rest of the elements of a recursive list s."""
    return s(1)
def len_rlist(s):
    """Return the length of recursive list s."""
    length = 0
    while s != empty_rlist:
        s, length = rest(s), length + 1
    return length

def getitem_rlist(s, i):
    """Return the element at index i of recursive list s."""
    while i > 0:
        s, i = rest(s), i - 1
    return first(s)


def make_dict():
        """Return a functional implementation of a dictionary."""
        records = make_mutable_rlist()
        len=0
        def getitem(key):
            length=records('len')
            for i in range(length):
                if records('getitem',i)(0) == key:
                    return records('getitem',i)(1)
            return None
            print('No such key')
        def setitem(key, value):
            nonlocal len
            for i in range(records('len')):
                if records('getitem',i)(0) == key:
                    records('getitem',i)(1,value)
                    return
            records("push_first",make_pair(key,value))
            len=len+1
        def dispatch(message,key=None,value=None):
            def dispatch2(key=None,value=None):
                if message == 'getitem':
                    return getitem(key)
                elif message == 'setitem':
                    setitem(key, value)
                elif message == 'str':
                    k='{'
                    for i in range(records('len')):
                        k+=str(records('getitem',i)(0))
                        k+=':'
                        k+=str(records('getitem',i)(1))
                        if(i<records('len')-1):
                            k+=','
                    k+='}'
                    return k
                elif message=='len':
                    return len
            return dispatch2
        return dispatch
    
    




def make_instance(cls):
        """Return a new object instance, which is a dispatch dictionary."""
        attributes = make_dict()
        def get_value(name):
            if attributes('getitem')(name)!=None:
                return attributes('getitem')(name)
            else:
                value = cls('getitem')('get')(name)
            return bind_method(value, instance)
        def set_value(name, value):
            attributes('setitem')(name,value)
        instance = make_dict()
        instance('setitem')('get',get_value)
        instance('setitem')('set',set_value)
        return instance

def bind_method(value, instance):
        """Return a bound method if value is callable, or value otherwise."""
        if callable(value):
            def method(*args):
                return value(instance, *args)
            return method
        else:
            return value
        
def make_class(attributes, base_class=None):
        """Return a new class, which is a dispatch dictionary."""
        def get_value(name):
            if attributes('getitem')(name)!=None:
                return attributes('getitem')(name)
            elif base_class is not None:
                return base_class('getitem')('get')(name)
        def set_value(name, value):
            attributes('setitem')(name,value)
        def new(*args):
                return init_instance(cls, *args)
        cls = make_dict()
        cls('setitem')('get',get_value)
        cls('setitem')('set',set_value)
        cls('setitem')('new',new)
        return cls
    
def init_instance(cls, *args):
        """Return a new object with type cls, initialized with args."""
        instance = make_instance(cls)
        init = cls('getitem')('get')('__init__')
        if init:
            init(instance, *args)
        return instance
    
def make_Point_class():
    """return point class"""
    count=0
    def __init__(self,x=0,y=0):
        nonlocal count
        self('getitem')('set')('x',x)
        self('getitem')('set')('y',y)
        count+=1
    def strr(self):
        return '(%d,%d)' % (self('getitem')('get')('x'), self('getitem')('get')('y'))
    def counter(self=None):
        return count
    def prt(self):
        print(self('getitem')('get')('str')())
    def shift(self, number):
        self('getitem')('set')('x',self('getitem')('get')('x')+ number)
        self('getitem')('set')('y',self('getitem')('get')('y')+ number)
    def eq(self, other):
        return self('getitem')('get')('x') == other('getitem')('get')('x')  and  self('getitem')('get')('y') == other('getitem')('get')('y')
    def getX(self):
        return self('getitem')('get')('x')
    def getY(self):
        return self('getitem')('get')('y')
    def setX(self,x):
        self('getitem')('set')('x',x)
    def setY(self,y):
        self('getitem')('set')('y',y)
    def distance(self,other):
        return (((self('getitem')('get')('x')-other('getitem')('get')('x'))**2)+((self('getitem')('get')('y')-other('getitem')('get')('y'))**2))**0.5
    dict=make_dict()
    dict('setitem')('__init__',__init__)
    dict('setitem')('str',strr)
    dict('setitem')('print',prt)
    dict('setitem')('shift',shift)
    dict('setitem')('==',eq)
    dict('setitem')('counter',counter)
    dict('setitem')('setX',setX)
    dict('setitem')('setY',setY)
    dict('setitem')('getX',getX)
    dict('setitem')('getY',getY)
    dict('setitem')('distance',distance)
    return make_class(dict)
print("*******************Targeil 1 Bet*******************"   
print("***PointClassDriver***")
print(">>>Point = make_Point_class()")
Point = make_Point_class()
print(">>>p1 = Point('getitem')('new')(4,5)")
p1 = Point('getitem')('new')(4,5)
print(">>>p1('getitem')('get')('str')()")
print(p1('getitem')('get')('str')())
print("drver=(4,5)")
print(">>>p1('getitem')('get')('setY')(3)")
p1('getitem')('get')('setY')(3)
print(">>>p1('getitem')('get')('str')()")
print(p1('getitem')('get')("str")())
print("driver=(4,3)")
print(">>>p2 = Point('getitem')('new')()")
p2 = Point('getitem')("new")()
print("p2('getitem')('get')('str')()")
print(p2('getitem')('get')("str")())
print("driver=(0,0)")
print("p1('getitem')('get')('distance')(p2)")
print(p1('getitem')('get')("distance")(p2))
print("driver=5")

def make_Line_class():
    count=0
    def __init__(self,p1=Point('getitem')('new')(),p2=Point('getitem')('new')()):
        nonlocal count
        self('getitem')('set')('p1',p1)
        self('getitem')('set')('p2',p2)
        count+=1
    def initAB(self):
        if(self('getitem')('get')('p1')('getitem')('get')('==')(self('getitem')('get')('p2'))):
            a=None
            b=None
        elif self('getitem')('get')('p1')('getitem')('get')('getY')()==self('getitem')('get')('p2')('getitem')('get')('getY')():
            a=0
            b=self('getitem')('get')('p1')('getitem')('get')('getY')()
        elif self('getitem')('get')('p1')('getitem')('get')('getX')()==self('getitem')('get')('p2')('getitem')('get')('getX')():
            a=None
            b=None
        else:
            a=(self('getitem')('get')('p1')('getitem')('get')('getY')()-self('getitem')('get')('p2')('getitem')('get')('getY')())/(self('getitem')('get')('p1')('getitem')('get')('getX')()-self('getitem')('get')('p2')('getitem')('get')('getX')())
            b= self('getitem')('get')('p1')('getitem')('get')('getY')()-a*self('getitem')('get')('p1')('getitem')('get')('getX')()  
        return a,b                                         
    def strr(self):
        a,b=initAB(self)
        if(a==None and b==None):
            if(self('getitem')('get')('p1')('getitem')('get')('getY')()!=self('getitem')('get')('p2')('getitem')('get')('getY')()):
                return 'x=%d'%(self('getitem')('get')('p1')('getitem')('get')('getX')())
            else:
                return 'Not a line'
        if(a):
            return 'y=%0.2fx+%0.2f'%(a,b)
        else:
            return 'y=%0.2f'%(b)
    def setPoint(self,i,x,y):
        if(i==1):
            self('getitem')('get')('p1')('getitem')('get')('setX')(x)
            self('getitem')('get')('p1')('getitem')('get')('setY')(y)   
        elif(i==2):
            self('getitem')('get')('p2')('getitem')('get')('setX')(x)
            self('getitem')('get')('p2')('getitem')('get')('setY')(y) 
        else:
            print(str(i)+'is wrong index,there is only 1-for first point and 2-for the second point')
    def getPoint(self,i):
        if(i==1):
            return Point('getitem')('new')(self('getitem')('get')('p1')('getitem')('get')('getX')(),self('getitem')('get')('p1')('getitem')('get')('getY')())
        elif(i==2):
            return Point('getitem')('new')(self('getitem')('get')('p2')('getitem')('get')('getX')(),self('getitem')('get')('p2')('getitem')('get')('getY')())
        else:
            print(str(i)+'is wrong index,there is only 1-for first point and 2-for the second point')   
    def isOnLine(self,otherP):
        a,b=initAB(self)
        if (otherP('getitem')('get')('getY')()-a*otherP('getitem')('get')('getX')()-b) :
            return False
        return True
    dict=make_dict()
    dict('setitem')('__init__',__init__)
    dict('setitem')('str',strr)
    dict('setitem')('isOnLine',isOnLine)
    dict('setitem')('setPoint',setPoint)
    dict('setitem')('getPoint',getPoint)
    dict('setitem')('initAB',initAB)
    return make_class(dict)
print("***LineClassDrier***")
print(">>>Line = make_Line_class()")
Line = make_Line_class()
print(">>>l1 = Line('getitem')('new')()")
l1 = Line('getitem')('new')()
print(">>>l1('getitem')('get')('setPoint')(1,2,3)")
l1('getitem')('get')("setPoint")(1,2,3)
print(">>>l1('getitem')('get')('setPoint')(2,8,6)")
l1('getitem')('get')("setPoint")(2,8,6)
print(">>>l1('getitem')('get')('str')()")
print(l1('getitem')('get')("str")())
print("driver= y = 0.5x + 2")
print(">>>p = l1('getitem')('get')('getPoint')(1)")
p = l1('getitem')('get')("getPoint")(1)
print(">>>l1('getitem')('get')('isOnLine')(p)")
print(l1('getitem')('get')("isOnLine")(p))
print("driver=True")

def make_Estimated_Line_class():
    count=0
    def __init__(self):
        nonlocal count
        self('getitem')('set')('distance',0)
        Line('getitem')('get')('__init__')(self)
    def getDistance(self):
        return self('getitem')('get')('distance')
    def setDistance(self,d):
        self('getitem')('set')('distance',d)
    def strr(self):
        return Line('getitem')('get')('str')(self)+' ; '+'%d'%(self('getitem')('get')('getDistance')())
    def isOnLine(self,p):
        a,b=self('getitem')('get')('initAB')()
        if(a==None and b==None):
            if(self('getitem')('get')('p1')('getitem')('get')('getY')()!=self('getitem')('get')('p2')('getitem')('get')('getY')()):
                if abs(self('getitem')('get')('p1')('getitem')('get')('getX')()-p('getitem')('get')('getX')())<=self('getitem')('get')('distance'):
                    return True
                return False
        elif self('getitem')('get')('distance')>=abs((a*p('getitem')('get')('getX')()-p('getitem')('get')('getY')()+b)/sqrt(a**2+1)):
            return True
        return False
    dict=make_dict()
    dict('setitem')('__init__',__init__)
    dict('setitem')('str',strr)
    dict('setitem')('isOnLine',isOnLine)
    dict('setitem')('setDistance',setDistance)
    dict('setitem')('getDistance',getDistance)
    return make_class(dict,Line)
print("***EstimatedLineClass***")
print(">>>E_Line = make_Estimated_Line_class()")
E_Line = make_Estimated_Line_class()
print(">>>el = E_Line('getitem')('new')()")
el = E_Line('getitem')('new')()
print(">>>el('getitem')('get')('setPoint')(1,1,6)")
el('getitem')('get')("setPoint")(1,1,6)
print(">>>el('getitem')('get')('setPoint')(2,3,2)")
el('getitem')('get')("setPoint")(2,3,2)
print(">>>el('getitem')('get')('setDistance')(5)")
el('getitem')('get')("setDistance")(5)
print(">>>el('getitem')('get')('str')()")
print(el('getitem')('get')('str')())
print("driver = y = -2x + 8 ; 5")
print(">>>p = Point('getitem')('new')()")
p = Point('getitem')('new')()
print(">>>el('getitem')('get')('isOnLine')(p)")
print(el('getitem')('get')("isOnLine")(p))
print("driver = True")
print(">>>el('getitem')('get')('setDistance')(3)")
el('getitem')('get')("setDistance")(3)
print(">>>el('getitem')('get')('isOnLine')(p)")
print(el('getitem')('get')("isOnLine")(p))
print("driver = False")
'''



def make_Print_Driver_singelton_class():
    '''Singelton class'''
    def make_printer():
        '''Printer class'''
        PrinterNo=0
        def __init__(self,name):
            self['set']('name',name)
        def activate(self,path):
            nonlocal PrinterNo
            PrinterNo=PrinterNo+1
            print('Job #%d: File %s is being printed.'%(PrinterNo,path))
        return make_class(locals())
    Element=None#printer
    def getPrinter(name):
        nonlocal Element
        if(Element==None):
            Printer = make_printer()
            Element=Printer['new'](name)
        if(name!=Element['get']('name')):
            print("Wrong name of printer!")
        return Element
    return make_class(locals())
    
 
print("Targil 2")
PrinterDriver = make_Print_Driver_singelton_class()
printer = PrinterDriver['get']("getPrinter")("myPrint")
printer['get']('activate')("myDoc\hello.py")
PrinterDriver['get']("getPrinter")("SecondPrinter")
PrinterDriver['get']("getPrinter")("myPrint")['get']("activate")("targil.docx")



class Node:
    '''Make a node  (x,y)'''
    ID=0
    def __init__(self,geoX,geoY,delayTime=0):
        self.GeoX=geoX
        self.GeoY=geoY
        self.delayTime=delayTime
        self.id=Node.ID
        Node.ID+=1
        
    def __str__(self):
        return 'node#{0} ({1},{2})'.format(self.id,self.GeoX,self.GeoY)
    
    def __eq___(self,other):
        return self.GeoX==other.GeoX and self.GeoY==other.GeoY
      
    

class Section:
    '''make a route from n1 to n2'''
    def __init__(self,n1,n2):
        self.n1=n1
        self.n2=n2
        self.avgSpeed=random.randrange(10,80)
        self.length=math.sqrt((n1.GeoX-n2.GeoX)**2+(n1.GeoY-n2.GeoY)**2)
    
    def ___str___(self):
        return 'from {0} to {1}'.format(str(self.n1),str(self.n2))
    
    def calAvgTime(self,userSpeed):
        time=(self.length*60)/min(self.avgSpeed,userSpeed)
        return time
    


class DirectionSection(Section): 
    '''make oneDerection route or double derection from n1 to n2'''
    def __init__(self,nFrom,nTo,oneDirection):
        super().__init__(nFrom,nTo)
        if oneDirection==0:
            self.oneDirection=False
        else:
            self.oneDirection=True
            
class NoRouteException(Exception):
    '''Exception for no route'''
    def __init__(self):
        self.massage='No such route exists'
        
class Navigation():
    '''
    class that have nodes
        can print them -printAllNodes:
                                param:none
                                return:none
        can cheack if there is a section from 1 node to other node - searchSection:
                                                                    param:id1,id2 - nodes indexes
                                                                    return section
        can calculate rote time-calcRouteTime:
                                param:start,end-Nodes
                                return time from one to other 
        can make a rote time calulate for timing navigate:
                                                param:id1,id2 - node indexes
    '''
    def __init__(self,transport,nodesList,SectionList):
        self.nodes=[]
        self.section=[]
        self.transport={"walk":6,"car":random.randrange(10,70),"bicycle":random.randrange(8,16)}
       
        for v in nodesList:
            self.nodes.append(Node(v[0],v[1],v[2]))
            
        for v in SectionList:
            if v[0]<len(nodesList) and v[1]<len(nodesList):
                self.section.append(DirectionSection(self.nodes[v[0]],self.nodes[v[1]],v[2]))
            else:
                print("There is incorrect id's")       
        if transport in self.transport.keys():
            self.userSpeed=self.transport[transport]
        else:
            print("No such transport!!!")
            
            
    def printAllNodes(self):
        for v in self.nodes:
            print(str(v)+' delay:%d'%v.delayTime)
            
    def calcRouteTime(self,start,end):
        if start==end:
            return 0;
        section = self.searchSection(start.id,start.id+1)
        return section.calAvgTime(self.userSpeed)+self.nodes[start.id+1].delayTime+self.calcRouteTime(self.nodes[start.id+1],end)

         
    
    def searchSection(self,id1,id2):
            for v in self.section:
                if v.n1.id==id1 and v.n2.id==id2:
                    return v
                elif v.n2.id==id1 and v.n1.id==id2 and v.oneDirection==False:
                    return v  
            raise NoRouteException
    
    def navigate(self,id1,id2):
        if id1>=0 and id1<=len(self.nodes) and id2>=0 and id2<=len(self.nodes) and id1<id2:
            try:
                Time=self.calcRouteTime(self.nodes[id1],self.nodes[id2])
            except NoRouteException as error:
                print(error.massage)
            else:
                print('navigation time: %.3f min'%Time)
                
        else:
            print('please make sure you enter correct ids')
            
                
    
nodesList=((31.251764, 34.791202, 3), (31.252042, 34.786731, 2),
(31.251679, 34.793161, 1), (31.250381, 34.784395, 2),
(31.247839, 34.783515, 2), (31.246378, 34.782915, 1),
(31.245723, 34.786335, 3), (31.246487, 34.787483, 3),
(31.245117, 34.789172, 1), (31.248612, 34.789633, 2),
(31.250666, 34.790588, 1))

sectionsList=((0,1,0),(0,2,1),(1,3,0),(3,4,0),(4,5,0),(5,6,0),(7,6,1),(6,8,0),(7,9,0),(9,10,1),(10,0,0))
print("Targil 3")
wise=Navigation(input('choose transportation: walk/car/bicycle: '),nodesList,sectionsList)
wise.printAllNodes()
print('navigate')
startId=int(input('from:'))
endId=int(input('to:'))
wise.navigate(startId,endId)


