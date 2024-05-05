let animationSpeed = 50;
let graph;

document.addEventListener('DOMContentLoaded', () => {
  const canvas = document.getElementById('graphCanvas');
  const ctx = canvas.getContext('2d');
  const startNodeInput = document.getElementById('startNode');
  const startButtonDFS = document.getElementById('startDFSButton');
  const startButtonBFS = document.getElementById('startBFSButton');
  const fileInput = document.getElementById('fileInput');
  const loadGraphButton = document.getElementById('loadGraphButton');
  let animationFrameId;

  function createAdjacencyList(edges, numNodes) {
    const adjacencyList = new Array(numNodes).fill().map(() => []);

    edges.forEach(edge => {
      const [node1, node2] = edge;

      adjacencyList[node1 - 1].push(node2);
      adjacencyList[node2 - 1].push(node1);
    });

    return adjacencyList;
  }

  function convertGraphData(data) {
    const numNodes = data.nodes.length;
    return {
      nodes: data.nodes.map(({ x, y }) => ({ x, y })),
      edges: data.edges,
      adjacencyList: createAdjacencyList(data.edges, numNodes)
    };
  }

  let edgeStates;
  let colorGradient;
  let edgeColors;
  let nodeColors;

  function initializeGraphState() {
    edgeStates = Array(graph.edges.length).fill('unvisited');
    colorGradient = ['#3498db', '#1abc9c', '#e74c3c', '#f39c12', '#9b59b6', '#2c3e50'];
    edgeColors = Array(graph.edges.length).fill('#bdc3c7');
    nodeColors = Array(graph.nodes.length).fill('#bdc3c7');
  }

  function drawGraph(visitedNodes = [], currentVisit = null) {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
  
    ctx.strokeStyle = '#000';
    ctx.lineWidth = 2;
    graph.edges.forEach((edge, index) => {
      const start = graph.nodes[edge[0] - 1];
      const end = graph.nodes[edge[1] - 1];
  
      ctx.strokeStyle = edgeColors[index];
      ctx.beginPath();
      ctx.moveTo(start.x, start.y);
      ctx.lineTo(end.x, end.y);
      ctx.stroke();
    });
  
    ctx.font = 'bold 18px Arial';
    graph.nodes.forEach((node, index) => {
      const isVisited = visitedNodes.includes(index + 1);
  
      ctx.fillStyle = nodeColors[index];
  
      ctx.beginPath();
      ctx.arc(node.x, node.y, 20, 0, 2 * Math.PI);
      ctx.fill();
      ctx.stroke();
  
      ctx.fillStyle = '#fff';
      const textWidth = ctx.measureText(index + 1).width;
      ctx.fillText(index + 1, node.x - textWidth / 2, node.y + 6);
    });
  
    ctx.strokeStyle = '#000';
    ctx.lineWidth = 2;
  
    if (currentVisit !== null) {
      const currentNode = graph.nodes[currentVisit - 1];
      ctx.fillStyle = '#add8e6'; 
      ctx.beginPath();
      ctx.arc(currentNode.x, currentNode.y, 22, 0, 2 * Math.PI);
      ctx.fill();
    }
  }

  async function dfs(startNode) {
    nodeColors = Array(graph.nodes.length).fill('#bdc3c7');
    drawGraph();
  
    const stack = [];
    const visited = new Array(graph.nodes.length).fill(false);
    const visitedNodes = [];
  
    stack.push(startNode);
    document.getElementById('containerStatus').innerText = `Stack Status: Push node ${startNode}`;
  
    while (stack.length !== 0) {
      const node = stack.pop();
      document.getElementById('containerStatus').innerText = `Stack Status: Pop node ${node}`;
  
      if (!visited[node - 1]) {
        visited[node - 1] = true;
        visitedNodes.push(node);
        document.getElementById('dfsStatus').innerText = `DFS Status: Visiting node ${node}`;
  
        nodeColors[node - 1] = '#03a9fc';
        drawGraph(visitedNodes, node);
        await sleep(500);
  
        const neighbors = graph.adjacencyList[node - 1];
  
        for (let i = 0; i < neighbors.length; i++) {
          const neighbor = neighbors[i];
          const edgeIndex = graph.edges.findIndex(
            edge =>
              (edge[0] === node && edge[1] === neighbor) || (edge[1] === node && edge[0] === neighbor)
          );
  
          if (!visited[neighbor - 1]) {
            edgeColors[edgeIndex] = colorGradient[visitedNodes.length % colorGradient.length];
            stack.push(neighbor);
            document.getElementById('containerStatus').innerText = `Stack Status: Push node ${neighbor}`;
            drawGraph(visitedNodes, node);
            await sleep(500);
            edgeColors[edgeIndex] = '#bdc3c7';
            drawGraph(visitedNodes, node);
          }
        }
  
        drawGraph(visitedNodes, node);
        await sleep(500);
      }
    }
  
    for (const visitedNode of visitedNodes) {
      nodeColors[visitedNode - 1] = 'lightcoral';
    }
    drawGraph(visitedNodes);
  
    document.getElementById('dfsStatus').innerText = `DFS Status: Completed`;
    document.getElementById('containerStatus').innerText = `Stack Status: Empty`;
  }
  
  async function bfs(startNode) {
    nodeColors = Array(graph.nodes.length).fill('#bdc3c7');
    drawGraph();
  
    const queue = [];
    const visited = new Array(graph.nodes.length).fill(false);
    const visitedNodes = [];
  
    queue.push(startNode);
    document.getElementById('containerStatus').innerText = `Queue Status: Push node ${startNode}`;
  
    while (queue.length !== 0) {
      const node = queue.shift();
      document.getElementById('containerStatus').innerText = `Queue Status: Pop node ${node}`;
  
      if (!visited[node - 1]) {
        visited[node - 1] = true;
        visitedNodes.push(node);
        document.getElementById('dfsStatus').innerText = `BFS Status: Visiting node ${node}`;
  
        nodeColors[node - 1] = '#03a9fc';
        drawGraph(visitedNodes, node);
        await sleep(500);
  
        const neighbors = graph.adjacencyList[node - 1];
  
        for (let i = 0; i < neighbors.length; i++) {
          const neighbor = neighbors[i];
          const edgeIndex = graph.edges.findIndex(
            edge =>
              (edge[0] === node && edge[1] === neighbor) || (edge[1] === node && edge[0] === neighbor)
          );
  
          if (!visited[neighbor - 1]) {
            edgeColors[edgeIndex] = colorGradient[visitedNodes.length % colorGradient.length];
            queue.push(neighbor);
            document.getElementById('containerStatus').innerText = `Queue Status: Push node ${neighbor}`;
            drawGraph(visitedNodes, node);
            await sleep(500);
            edgeColors[edgeIndex] = '#bdc3c7';
            drawGraph(visitedNodes, node);
          }
        }
  
        drawGraph(visitedNodes, node);
        await sleep(500);
      }
    }
  
    for (const visitedNode of visitedNodes) {
      nodeColors[visitedNode - 1] = 'lightcoral';
    }
    drawGraph(visitedNodes);
  
    document.getElementById('dfsStatus').innerText = `BFS Status: Completed`;
    document.getElementById('containerStatus').innerText = `Queue Status: Empty`;
  }

  function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms * (25 / animationSpeed)));
  }

  document.getElementById('animationSpeed').addEventListener('input', function () {
    animationSpeed = this.value;
  });

  function startDFS() {
    const startNode = parseInt(startNodeInput.value);
    if (isNaN(startNode) || startNode < 1 || startNode > graph.nodes.length) {
      alert('Invalid start node. Please enter a number between 1 and ' + graph.nodes.length);
      return;
    }

    animationFrameId = undefined;

    const visited = Array(graph.nodes.length).fill(false);
    const visitedNodes = [];
    dfs(startNode, visited, visitedNodes);
  }

  function startBFS() {
    const startNode = parseInt(startNodeInput.value);
    if (isNaN(startNode) || startNode < 1 || startNode > graph.nodes.length) {
      alert('Invalid start node. Please enter a number between 1 and ' + graph.nodes.length);
      return;
    }

    animationFrameId = undefined;

    const visited = Array(graph.nodes.length).fill(false);
    const visitedNodes = [];
    bfs(startNode, visited, visitedNodes);
  }

  function loadGraph() {
    const file = fileInput.files[0];
    if (file) {
      const reader = new FileReader();

      reader.onload = async function (e) {
        try {
          const rawData = JSON.parse(e.target.result);
          graph = convertGraphData(rawData);
          initializeGraphState();
          drawGraph();
        } catch (error) {
          console.error('Error parsing graph data:', error);
        }
      };

      reader.readAsText(file);
    }
  }

  startButtonDFS.addEventListener('click', startDFS);
  startButtonBFS.addEventListener('click', startBFS);
  loadGraphButton.addEventListener('click', loadGraph);

  drawGraph();
});
