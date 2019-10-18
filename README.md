# hashAlgorithm
Not-so-smart hashing algorithm for the Blockchain class.

# Features
- Single function  to generate a constant length hash from any string
- Reasonably fast and efficient for diferent inputs
- Lithuanian symbols support
- Random enough to satisfy requirments of the task

 
# Improvements to make

- Beggining of the hash is not random enough, need to find a more optimised solution
- Only 20 hard-coded ASCII characters supported for the hash, increase this amount

# How to run?

Simply compile the stringToHash.cpp with your favorite compiler. You can also pass command line arguments. Test is runned automatically.

# Tests output v1

```
5841068239935ec53aga5bd4
584ajjgd99cf99fe9aa468cd
5848egc339cab8ad5ag818h9
585207a449cfa9ed8aa469be
584ahhd879cf95721aa448gb
584aj93889cf95c82aa448ac
Failo konstitucija.txt eiluciu hashavimo laikas: 0.024403

Rasta 5105 pasikartojimu
Vidutinis panasumo procentas: 28.8663%
Min panasumo procentas: 12%
Max panasumo procentas: 45.5%
```

# Tests output v2

```
29a97553544309gca88957c835a78eg9244763bg704cece91886847b856966aa
3aaad99faad5225406719j949589477chb37c859dbbfe8535bd76c99c86ac89f
2b98ef96dfb4ajeaegb9df73c9345847d85cc5976ehhddc525cfdfjc42452359
5ed89b62beed89b62b9129gha325d803b84969dddb6018832366998720011299
49cb9549a99cb9549a59a5d909a1002ab97abaa3100136bgb6cc5364007a989c
18d61468eg8ac975afebdb67ee75634bb558ca5agb59727cfe6696236668bec7
Failo konstitucija.txt eiluciu hashavimo laikas: 0.000000

Rasta 0 pasikartojimu
Vidutinis panasumo procentas: 34.0799%
Min panasumo procentas: 21.2891%
Max panasumo procentas: 44.7266%
```

 
 
