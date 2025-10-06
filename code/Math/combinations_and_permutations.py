import itertools
a=[0]*N

b=list(itertools.combinations(a,r)) #조합
c=list(itertools.permutations(a,r)) #순열
d=list(itertools.product(a,repeat=r)) #중복순열
e=list(itertools.combiations_with_replacement(a,r)) #중복조합