program Carre_magique;

uses crt;

Const

        TAILLE=5;


Type //Déclaration du type tableau à 2 dim, pour utiliser dans les pramètres fcts
    //ou procédures


    Matrice=Array[1..TAILLE,1..TAILLE]of integer;

procedure init(var carreMagique:Matrice; var x,y,cpt:integer);

    var
    i,j:integer;

    BEGIN

    for i:=1 to TAILLE do
        begin
            for j:=1 to TAILLE do
            begin

                carreMagique[i,j]:=0;
            end;
        end;

    x:=(TAILLE) DIV 2;
    y:=(TAILLE) DIV 2+1;
    carreMagique[x,y]:=1;
    cpt:=2;


    END;

procedure corriger(var x,y:integer);

    BEGIN

    
    if x<1 then
        x:=TAILLE;
    if y>TAILLE then
        y:=1;
    if y<1 then
        y:=TAILLE;



    END;


procedure nordEst(var x,y:integer);



    BEGIN

    x:=x-1;
    y:=y+1;
    corriger(x,y);

    END;

procedure nordOuest(var x,y:integer);



    BEGIN

    x:=x-1;
    y:=y-1;
    corriger(x,y);


    END;

procedure testVide(carreMagique:Matrice; var x,y:integer);



    BEGIN

    while (carreMagique[x,y]<>0) do
        begin
            nordOuest(x,y);
        end;


    END;

procedure placer(var carreMagique:Matrice; x,y,cpt:integer);



    BEGIN

    carreMagique[x,y]:=cpt;


    END;






procedure affiche(carreMagique:Matrice);

    var
    i,j:integer;

    BEGIN

    for i:=1 to TAILLE do
        begin
            for j:=1 to TAILLE do
            begin

                write(carreMagique[i,j]);
                write(' ');
            end;
            writeln;
        end;





    END;




//programme principal

var

    carreMagique:Matrice;
    x,y:integer;
    cpt:integer;
   


BEGIN

    writeln('Programme Carre Magique');

    
    clrscr;
    init(carreMagique,x,y,cpt);
    while(cpt<=TAILLE*TAILLE)do
      
        begin
                nordEst(x,y);
                testVide(carreMagique,x,y);
                placer(carreMagique,x,y,cpt);
                cpt:=cpt+1;

        end;
   

        affiche(carreMagique);



    readln;


END.