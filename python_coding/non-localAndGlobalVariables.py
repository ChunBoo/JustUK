#https://docs.python.org/3/reference/simple_stmts.html#the-nonlocal-statement
'''
With nonlocal x, inner() can access the non-local variable x in middle() 
but not the non-local variable x in outer() or the global variable x outside outer() as shown below:
With global x, inner() can access the global variable x outside outer()
but not the non-local variable x in outer() or middle() as shown below:



'''
x = 0 # <- ✖ X
def outer():
    x = 5 # <- ✖
    def middle():
        # x = 10 # <- 〇
        def inner():
            nonlocal x # Here will bind to the closet x which is a local variable!!!!
            x += 1
            print(x) # 11
        inner()
    middle()
outer()


# g_x=0
def OUTER():
    g_x=5
    def middle():
        g_x=10
        def inner():
            global g_x
            g_x+=1
            print(g_x)
        inner()
    middle()
OUTER()