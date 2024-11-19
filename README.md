# Guardian - Monitoramento Climático Sustentável

Este repositório contém o código fonte do projeto Guardian, uma solução baseada em Arduino para monitoramento de condições climáticas e identificação da melhor fonte de energia renovável em diferentes regiões.

## Link para o projeto no WOKWI e video no Youtube

[Acesse o Projeto no WOKWI clicando aqui](https://cp1-front-web.vercel.app/)

[Acesse o video explicativo no Youtube clicando aqui](https://youtu.be/62gEc4FMRlM)

## Desenvolvedores

- Rafael Mandel, 560333

- Luigi Thinego, 560755

- Felipe Silva, 559848

## Resumo do Projeto

O projeto Guardian utiliza sensores e componentes eletrônicos para coletar dados como temperatura, umidade, velocidade do vento e relevo. Esses dados são analisados para recomendar a fonte de energia mais eficiente para as condições monitoradas, como energia eólica, solar ou hidrelétrica.

## Tecnologias e Componentes Utilizados

- **Linguagem**: C++

- **Arduino**: Plataforma principal do sistema.

- **DHT22**: Sensor de temperatura e umidade.

- **Potenciômetros**: Simulação de dados de velocidade do vento e altitude do relevo.

- **LiquidCrystal_I2C**: Display LCD para exibição dos dados coletados e análises.

## Funcionalidades

1. **Monitoramento Climático:**

    - Coleta de temperatura e umidade do ar utilizando o sensor DHT22.

    - Leitura simulada de dados de velocidade do vento e altitude do relevo.

2. **Recomendação de Fontes de Energia:**

    - Energia Eólica: Recomendada para condições de vento acima de 20 km/h e temperaturas abaixo de 30°C.

    - Energia Solar: Sugerida para temperaturas acima de 30°C e alta umidade.

    - Energia Hidrelétrica: Indicada para regiões com relevo acima de 800 metros.

    - Combinação de energias: Utilizada em condições não ideais para uma única fonte.

3. **Interface Simples e Interativa:**

    - Exibição dos dados coletados e resultados em um display LCD.

## Como Executar o Projeto

1. **Montagem do Circuito:**

    - Conecte o sensor DHT22 ao pino digital 2 do Arduino.

    - Conecte os potenciômetros aos pinos analógicos A0 (vento) e A1 (relevo).

    - Conecte o display LCD à interface I2C do Arduino.

2. **Upload do Código:**

    - Utilize a IDE Arduino para compilar e carregar o código no Arduino.

    - Certifique-se de que as bibliotecas Wire, LiquidCrystal_I2C e DHT estejam instaladas na IDE Arduino.

3. **Visualização dos Resultados:**

    - Acompanhe os dados climáticos e as recomendações de energia diretamente no display LCD.

## Licença

Este projeto está licenciado sob a Licença MIT. Consulte o arquivo LICENSE para mais informações.