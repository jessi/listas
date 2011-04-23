Battle tank
===================

##Se agrego ejemplo grafico "lista_ordenada_grafica"

![imagen - lista_ordenada_grafica](https://github.com/jessi/listas/raw/master/lista_ordenada_grafica/img/nodos.png)

[lista_ordenada_grafica](https://github.com/jessi/listas/tree/master/lista_ordenada_grafica/)


Sólo que falta la libreria de la listas, ¿cual ocupo?, en fin.
son dos animaciones:
  ->listas ligadas(ordenadas//lista.h)
  ->listas circulares(ordenadas)

###Caracteristicas principales:

 - **Resolución:** wvga(850,480px)
 - **Velocidades:** [1-5]
  - Por cada bono del tipo "rapidez" el nivel se incrementa en 1.
 - **Gasolina:** [0-100%]
  - Una vez acabado la gasolina en 10segundos se le llena un 25% de su tanque
  - Por cada bono del tipo "carga_gasolina" el nivel se incrementa en 30pts
 - **Alanze del proyectil:** [2,10].
  - inicia con un valor de 2
  - por cada bono del tipo "alcanze_proyectil" este alcanze se incrementa en 1
  - Cada proyectil daña desincrementa estado de un tanque por 30ptos
 - **Estado:** [0-100];
  - El estado inicial es de 100
  - Si el estado llega a 0 el tanque esta fuera(destruido).
  - Por cada bono del tipo "cruz_roja" el nivel se incrementa en 40pts.
 - **Vidas:**
  - Empieza con 3 vidas
  - Por cada 1000 que alcanze en score se incrementa en uno.
  - Por cada bono del tipo "nueva_vida" la cantidad de vidas se incrementa en 1.
 - **score:**
	- Por cada bloque destruido se incrementa en 10
	- Por cada disparo que colisione con algun enemico se incrementa en 
	- Si consume un bono "rapidez" y su velcidad es de 5, se incrementa en
	- Si consume un bono "alcanze_proyectil" y su alcanze es de 10, se incrementa en
	- Si consume un bono "cruz_roja" y su estado es de 100, se incrementa en
	
 
###Bonos

 - **carga_gasolina**
 - **alcanze_proyectil**
 - **cruz_roja**
 - **rapidez**
 - **nueva_vida**
 
##imagenes.

Las imagenes que se requieren para el juego son las descritas acontinuación:

####Lista de Imagnes
 - **Tanques**;
  - Resolución: 304x38px
  - Fuente: tanque1.png, tanque2.png
  - sprite de 8x4 con sub-imagenes de 38x38px
 - **Balas**
  - Resolución: 10x40px
  - Fuente: balas.png
  - sprite de 1x4 con sub-imagenes de 10x10px
 - **Fondos**
  - Resolución 150x50px
  - Fuente: fondos.png
  - sprite de 3x1 con sub-imagenes de 50x50px
 - **Bonos**
  - Resolución 250x50px
  - Fuente: bonos.png
  - sprite de 5x1 con sub-imagenes de 50x50px
   - carga_gasolina
   - alcanze_proyectil
   - cruz_roja
   - rapidez
   - nueva_vida

##Librerias utilizadas

###tanques.h

Contiene y administra la siguiente estructura:

	typedef struct tanque
	{
		int x;
		int y;
		int cuadro;
		int velocidad,score,gasolina,estado,nvidas,alcanzeproyectil;
		SDL_Surface * ima;
	} Tanque;

los metodos que contiene son:
	
	void iniciar_tanque (Tanque * tanque);
	int tanque_modificarVelocidad(Tanque * tanque, int velocidad);
	int incrementar_velocidad_tanque(Tanque * tanque);
	int desincrementar_velocidad_tanque(Tanque * tanque);

###lista_enemigos.h

Administra una lista de nodos con Tanque como tipo de dato.

