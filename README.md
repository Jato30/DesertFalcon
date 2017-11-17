# DesertFalcon

Repositório do jogo estilo Desert Falcon do Atari para a disciplina de TP2 2017-2. Atualmente sem licença



**Desert Falcon** é baseado num clássico do atari em que você é um falcão e deve voar pelo deserto capturando hieros para juntar pontos.  
  
#### Objetivo do jogo:
Fazer a maior quantidade dde pontos possível.

#### Controles:
- `A D` para movimentação do falcon
- `W S` para movimentação da altura do falcon
- `Space bar` para atirar

#### Dependências:
- SDL2
- SDL2_mixer
- SDL2_TTF
- SDL2_image
- MingW **(Windows)**
- Compilador g++ com padrão de codificação C++11

## Como compilar
**No linux:**
Após instalar as dependências, baixe o projeto no github e rode o comando:  

`make release`
`make help` para ajuda de comandos

O executável terá o nome JOGO

**No windows:**
Após instalar as dependências, baixe o projeto no github e rode o comando:

`mingw32-make release`
`mingw32-make help` para ajuda de comandos

O executável terá o nome JOGO.exe


Link para documentação doxygen: [https://jato30.github.io/DesertFalcon](https://jato30.github.io/DesertFalcon)


----------------------------------
Sistema de uso do repositório (em adaptação):
- Branch dev saindo da master.
- Um branch para cada feature saindo de dev. O branch será nomeado "feature/*", em que "*" será o nome da feature. Exemplo "feature/EndScreen".
- Para juntar qualquer feature ao dev, será um pull request que deve ser revisado e testado por pelo menos um outro programador, ou seja, você nunca aceitará seus próprios pull requests. O branch será excluído assim que o pull request for aceito e realizado.
- Se uma feature for complexa (por exemplo UI), vc pode fazer sub branches. Exemplo "feature/UI/ScreenAnimation". Todas as regras acima se aplicam.
- Por padrão, o código devera ser completamente feito em inglês e o padrão CamelCase. Com exceção dos comentários e documentação que devem ser escritos no bom português.
- Semanalmente, far-se-á um merge do tweaks (descrito mais abaixo) paro master e depois da dev pra master, atualizando o número da versão MINOR. E depois um merge da master pra dev. (Esse tópico pode ser discutível, pois o prazo de entrega é curto)
- A documentação deve estar atualizada e refletindo com precisão a branch dev ANTES do merge ser feito.
- Extremamente recomendável de que cada pull request de features já estejam com sua documentação correta.
- Merges e pull requests só devem ser feitos se o código compilar e executar sem game-breaking bugs.
- Branches de correção de bugs saem da master com nomenclatura "bugfix/*". Onde * é o número da issue no github. Exemplo "bugfix/32".
- Branches de bugfix se juntam à master da mesma forma que uma feature se junta à dev. Mas atualizando a versão de patch.
- Tweaks serão branches saindo da master. Eles serão feitos de commits únicos que ajustam coisas. Tipo nome de arquivo de música, texto que aparece sei lá onde, etc.
- A branch tweaks não receberá um merge da master toda vez, somente pela primeira vez que for ter um patch naquela versão. Cada commit altera o número da versão de patch.
- A numeração de versão será semântico, ou seja, MAJOR.MINOR.PATCH.TWEAK . Qualquer atualização em um número zera todos os números à sua direita.
- Commits DEVEM ter nomes (e, se aplicáveis, resumos) descritivos. Nada de "asdfgh" ou "teste", etc...
- Se possível, colocar um resumo de tudo que foi alterado em um pull request.

