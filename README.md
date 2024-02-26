# ponderada_DHT
### Caso de Teste 1: Inserção de Itens

Descrição: Testar a inserção de diferentes produtos na Hash Table e verificar se eles são alocados nas posições corretas com base em seu código.\
Procedimento: Inserir produtos com códigos únicos e verificar se cada produto é colocado na lista correta da tabela hash.\
Expectativa: Cada produto deve ser inserido na posição correspondente ao seu código hash.


### Caso de Teste 2: Tratamento de Colisões

Descrição: Testar a a colisão de produtos, ou seja, que tenha o mesmo hash.\
Procedimento: Inserir produtos com códigos diferentes que resultam no mesmo código hash e verificar se eles são adicionados à mesma lista.\
Expectativa: Produtos com o mesmo código hash devem coexistir na mesma lista da tabela hash.\

### Caso de Teste 3: Remoção de Itens

Descrição: Testar a remoção de produtos da Hash Table.\
Procedimento: Remover um produto específico da tabela hash e verificar se o produto foi removido corretamente.\
Expectativa: Após a remoção, o produto não deve estar presente na tabela hash.\

### Caso de Teste 4: Busca de Itens

Descrição: Testar a busca de produtos específicos na Hash Table.\
Procedimento: Buscar um produto específico pela sua chave e verificar se o produto correto é retornado.\
Expectativa: A busca pelo código do produto deve retornar o produto correto se existir na tabela hash.\

### Caso de Teste 5: Capacidade 

Descrição: Testar o comportamento da Hash Table ao se aproximar de sua capacidade máxima.\
Procedimento: Inserir uma quantidade de produtos que se aproxima do limite máximo de itens e verificar como a tabela hash se comporta.\
Expectativa: A tabela deve continuar operando corretamente conforme se aproxima de sua capacidade máxima.\

## Comprovação Caso de Testes
  <h6 align="center"> Caso de Testes </h6>

<div align="center">
	
![Caso_Teste](https://github.com/pedrofariasantos/ponderada_DHT/blob/main/imagenss/Captura%20de%20tela%202024-02-25%20200542.png)
</div>
