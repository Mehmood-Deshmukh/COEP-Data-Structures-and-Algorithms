const express = require('express');
const axios = require('axios');

const app = express();
const port = 3000;

app.use(express.json());

app.post('/execute-c', async (req, res) => {
  const { code } = req.body;

  if (!code) {
    return res.status(400).json({ error: 'No C code provided' });
  }

  try {
    // Submit the code to Judge0 API
    const submitResponse = await axios.post('https://judge0-ce.p.rapidapi.com/submissions', {
      language_id: 50, // ID for C (GCC 9.2.0)
      source_code: code,
      stdin: '',
    }, {
      headers: {
        'content-type': 'application/json',
        'X-RapidAPI-Host': 'judge0-ce.p.rapidapi.com',
        'X-RapidAPI-Key': 'd476650112mshce9dbca70399f75p1f18a8jsn398ffe13c414',
      },
    });

    const { token } = submitResponse.data;

    // Poll for the result
    let result;
    while (!result || result.status.description === 'Processing') {
      await new Promise(resolve => setTimeout(resolve, 1000)); // Wait for 1 second before polling again
      const resultResponse = await axios.get(`https://judge0-ce.p.rapidapi.com/submissions/${token}`, {
        headers: {
          'X-RapidAPI-Host': 'judge0-ce.p.rapidapi.com',
          'X-RapidAPI-Key': 'd476650112mshce9dbca70399f75p1f18a8jsn398ffe13c414',
        },
      });
      result = resultResponse.data;
    }

    if (result.status.id === 3) { // Accepted
      res.json({ output: result.stdout });
    } else {
      res.status(400).json({ error: result.stderr || result.status.description });
    }
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'An error occurred while processing your request' });
  }
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});