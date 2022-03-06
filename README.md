# Enigma
Aplikacja symulująca działanie maszyny szyfrującej Enigma.

### Zakres działania
Aplikacja operuje na znakach wyłączenie od 'A' do 'Z'.

## Zasada działania (mniej więcej)
Znaki pobierane są z ciągu znakowego podanego na wejście.
Każdy znak zaczyna drogę w **_łączynicy wtyczkowej (plugboard)_** gdzie zostaje zastąpiony na znak z przypisanej mu pary lub nie jeśli go tam nie ma.
Następnie trafia do **_bębnów mieszających (rotors)_** (których są trzy) gdzie zostaje podmieniony na odpowiedni z danego bębna.
Kolejnym etapem jest **_bęben odwracający (reflector)_**, który "odbija" znak jednocześnie zamieniając go.
Znak wraca odwrotną drogą i zostaje przypisany do ciągu znaków wyjściowych.

## Interfejs aplikacji
![enigma](https://user-images.githubusercontent.com/54991097/156934013-471f8c79-5063-4691-88ce-605607cee792.png)
