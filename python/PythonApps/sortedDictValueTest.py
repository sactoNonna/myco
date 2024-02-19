l = (('Eusebio', 120), ('cruyff', 104), ('pele', 150), ('ronaldo', 132), ('Messi', 125))
t = ('Eusebio', 120), ('Cruyff', 104), ('Pele', 150), ('Ronaldo', 132), ('Messi', 125)

if __name__ == '__main__':
    
    dt = dict(t)
    dl = dict(l)
    print(dt)
    print(dl)
    
    dts = dict(sorted(dt.items(), key=lambda x: x[1]))
    dls1 = dict(sorted(dl.items(), key=lambda x: x[0]))
    dls2 = dict(sorted(dl.items(), key=lambda x: x[0].upper()))
    print(dts)
    print(dls1)
    print(dls2)