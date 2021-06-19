int main(void)
{
	//////////////////////////////////////////////////////////// ENTENDENDO STRUCT
	struct {
		int		numero;
		char	*string;
	};
	// ñ faz nada apenas "ok senta la claudia"

	struct {
		int		subscribers;
		char	*string;
	} ms_stamps;
	ms_stamps.subscribers = 1000000;
	ms_stamps.string = "hullo";
	// apenas criei a minha variavel ms_stamps
	struct ms_stamps jenna_m;
	// u can try but u'll never be like ms_stamps

	struct queijo {
		char*	nacionalidade;
		int		derretencia;
		int		nota;
	};
	// só queijo parmesao nao funciona! tem q ter o struct antes
	struct queijo parmesao;
	parmesao.nacionalidade = "HueBr";
	parmesao.derretencia = 3;
	parmesao.nota = 8;
	struct queijo brie;
	brie.nacionalidade = "croissant";
	brie.derretencia = 10000454;
	brie.nota = 10;
	// obs. ñ dá pra instanciar tipo parmesao.nota, tem q primeiro criar o struct, depois designar os valores se quiser.

	struct data_fazendinha {
		int		dia;
		char	*estacao;
	};
	struct fazendinha {
		char *comida_favorita;
		char *conje;
		struct data_fazendinha niver;
	} player;
	player.comida_favorita = "Lemon pasta";
	player.conje = "Sebastian";
	player.niver.dia = 12;
	player.niver.estacao = "autumn";
	// BOOOOOOOMMMMMMMMM

	//////////////////////////////////////////////////////////// ENTENDENDO TYPEDEF
	typedef unsigned char BYTE;
	BYTE uma_variavel = 35;
	
	typedef enum {false, true} BOOLEAN;
	BOOLEAN uma_variavel_booleana = true;
	
	typedef unsigned long int SIZE_T;
	SIZE_T see_what_i_did_there = 100;

	//////////////////////////////////////////////////////////// ENTENDENDO STRUCT FEAT. TYPEDEF
	typedef struct linked_list
	{
		void				*conteudo;
		struct linked_list	*proximo_item;
	} item_da_lista;
	item_da_lista item1;
	item_da_lista item2;
	item_da_lista item3;
	// ATENSSAU que item_da_lista eh apenas um APELIDO para struct linked_list
	struct linked_list item4;
	struct linked_list item5;
	struct linked_list item6;
	item1.conteudo = (void *) "Eu sou o item um";
	item1.proximo_item = &item2;
	item2.conteudo = (void *) "Eu sou o item dois";
	item2.proximo_item = &item3;
	item3.conteudo = (void *) "Eu sou o item tres";
	item3.proximo_item = &item4;
	item4.conteudo = (void *) "Eu sou o item quatro";
	item4.proximo_item = &item5;
	item5.conteudo = (void *) "Eu sou o item cinco";
	item5.proximo_item = &item6;
	item6.conteudo = (void *) "Eu sou o item seis";
	item6.proximo_item = 0;
	// 6 eh o fim da lista e aponta para NULL.

	return (0);
}