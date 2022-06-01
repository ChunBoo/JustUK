
#given a string likes a emails address,it's name contains the '+' which should 
class Solution:
    def countOfUniqueEmails(self,emails):
        d=set()
        for email in emails:
            d.add(self.getSimpleEmail(email))
        return len(d)
    def getSimpleEmail(self,email):
        name,domain=email.split('@')
        #remove the + now
        name.split('+')[0].replace(".","")
        return name+'@'+domain
    
email=["a.b+cd@ms.com","aB..+acd@ms.com"]
s=Solution()
print(s.countOfUniqueEmails(email))
