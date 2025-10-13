const fs = require('fs');
const wav = require('wav');
const filename = process.argv[2];

let input;
const reader = new wav.Reader();
const out = [];

if (filename) {
  console.error('Header info for: %s', filename);
  input = fs.createReadStream(filename);
} else {
  console.error('Header info for: STDIN');
  input = process.stdin;
}

input.pipe(reader);

reader.on('format', function (format) {
  console.error(format);
  console.log('int SOUND_HELLO[] = {');
});

reader.on('data', function (data) {
  const numNotes = 32;
  const shift = numNotes / 256;
  for(let i=0; i<data.length; i+=16) {
    const v = Math.floor(data[i] * shift);
    const n = (v * 16) + 261;
    out.push(n);
  }
});

reader.on('end', function () {
  console.log(out.join(','));
  console.log('};');
});
