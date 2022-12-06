def removeDigit( number, digit):
        """
        :type number: str
        :type digit: str
        :rtype: str
        """
        n=len(number)
        ans=0
        for i in range(n):
            if number[i]==digit:
                ans=max(ans,int(number[:i]+number[i+1:]))
                
        return str(ans)
    
            