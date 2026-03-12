const express = require('express');

const PORT = 3000;
const app = express();

app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});

app.get('/', (req, res) => {
    res.send('<h1>Mohy Server!</h1>');
});
