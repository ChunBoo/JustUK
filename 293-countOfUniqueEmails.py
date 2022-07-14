
#given a string likes a emails address,it's name contains the '+' which should be removed
class Solution:
    def countOfUniqueEmails(self,emails):
        d=set()
        for e in emails:
            d.add(self.getSimpleEmail(e))
        return len(d)
    def getSimpleEmail(self,email):
        name,domain=email.split("@")
        _name=name.split("+")[0].replace(".","")
        return _name+"@"+domain
    
email=["a.b+cd@ms.com","aB..+acd@ms.com"]
s=Solution()
print(s.countOfUniqueEmails(email))
