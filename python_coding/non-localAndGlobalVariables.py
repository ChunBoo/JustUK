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