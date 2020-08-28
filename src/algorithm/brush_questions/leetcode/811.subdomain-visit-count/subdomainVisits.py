
from typing import List

def subdomain(domain: str)->List[str]:
    result = []
    components = domain.split('.')
    for i in range(len(components)):
        result.append('.'.join(components[i:]))
    return result

class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        result = dict()
        for cpdomain in cpdomains:
           [access, domain] = cpdomain.split(' ')
           for d in subdomain(domain):
               if d not in result:
                   result.setdefault(d, int(access))
               else:
                   result[d] = result[d] + int(access)
        return [ f'{result[k]} {k}' for k in result]