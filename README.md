# Lem_in
code an ant farm manager.

We needed to find a path to the end node, and then move all ours ants there. 

## Limitation

There may only be one ant in a node and we can only move the same ant once per a turn.

## Method
I generated Dijkstra to determine the shorted route to the end node.
For moving the ants I stored the ant current location/room inside of an int array, appropriately named "antarray".

## Output

The following are four different maps my ants had to move across.

The output format is as followed,

First we output the map that we read in. A map has to have a ##start and an ##end.

L1 : L followed by a number is the ant number

L1-bel : "bel" is the Room name. The Room name can be anything.

| Output        |               |
| ------------- |---------------|
| <img width="156" alt="screen shot 2018-09-12 at 10 54 10" src="https://user-images.githubusercontent.com/24510543/45413665-facf7c80-b679-11e8-9ec3-9df4af6b01e1.png">      | <img width="78" alt="screen shot 2018-09-12 at 10 53 58" src="https://user-images.githubusercontent.com/24510543/45413659-f905b900-b679-11e8-9500-e0aa864050a5.png"> |
| <img width="163" alt="screen shot 2018-09-12 at 10 53 48" src="https://user-images.githubusercontent.com/24510543/45413656-f7d48c00-b679-11e8-8a38-1d500976dcd3.png">      | <img width="88" alt="screen shot 2018-09-12 at 10 53 01" src="https://user-images.githubusercontent.com/24510543/45413653-f6a35f00-b679-11e8-92ae-54f98830d74d.png">      |


---
