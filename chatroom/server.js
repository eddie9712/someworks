const express = require('express');
const app = express();
const server = require('http').Server(app);
const io = require('socket.io')(server);
app.get('/', (req, res) => {
    res.send('Hello, World!');
});

app.listen(3000, () => {
    console.log("Server Started. http://localhost:3000");
});










