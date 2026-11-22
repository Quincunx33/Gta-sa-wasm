# GTA San Andreas — WebAssembly

<p align="center">
  <strong>Grand Theft Auto: San Andreas, running in the browser through WebAssembly.</strong>
  <br />
  An experimental PS2 recompilation project powered by <a href="https://github.com/ps2web/ps2web">PS2 Web Recomp</a>.
</p>

<p align="center">
  <a href="https://github.com/Quincunx33/Gta-sa-wasm/releases/tag/ios26-safari-latest6"><img src="https://img.shields.io/badge/Download-Safari%20Build-blue?style=for-the-badge" alt="Download Safari build" /></a>
  <a href="https://github.com/Quincunx33/Gta-sa-wasm/issues"><img src="https://img.shields.io/badge/Issues-Report%20a%20problem-orange?style=for-the-badge" alt="Report an issue" /></a>
  <a href="LICENSE"><img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="MIT License" /></a>
</p>

---

## Screenshots

### iOS · Safari 26

<p align="center">
  <img src="docs/screenshots/ios-safari-touch-controls.webp" alt="GTA San Andreas startup screen and touch controls in iOS Safari 26" width="820" />
  <br />
  <sub>iPhone / iPad · Startup screen and on-screen touch controls</sub>
</p>

### Desktop · Chrome

<p align="center">
  <img src="docs/screenshots/gtasa-intro-credits-cloud-chrome.webp" alt="GTA San Andreas intro and credits rendered in desktop Chrome" width="820" />
  <br />
  <sub>Desktop Chrome · Intro / credits frame</sub>
</p>

<p align="center">
  <img src="docs/screenshots/gtasa-runtime-diagnostics-cloud-chrome.webp" alt="Runtime diagnostics from a desktop Chrome test" width="820" />
  <br />
  <sub>Desktop Chrome · Runtime diagnostics from a separate test run</sub>
</p>

## Platform status

| Platform | Status |
|:--|:--|
| Desktop browsers | <strong>Gameplay working</strong> |
| Android browsers | <strong>Gameplay working</strong> |
| iOS Safari 26 | <strong>Experimental</strong> — gameplay not yet verified |

> The desktop and Android gameplay status is based on testing. The current iOS screenshot only confirms that the startup screen and touch controls appear; it does not demonstrate playable gameplay. Results may vary across devices and browsers.

## About

This project explores running the **PlayStation 2 version** of Grand Theft Auto: San Andreas in a modern web browser using WebAssembly.

The project uses [PS2 Web Recomp](https://github.com/ps2web/ps2web) and includes browser input support plus runtime loading of a game image supplied by the user. The goal is to make the experience work across desktop and mobile browsers, while investigating iOS Safari compatibility.

## Get a prebuilt build

The current published archive is the iOS Safari build:

**[Download GTASA-iOS26-Safari-latest6.zip](https://github.com/Quincunx33/Gta-sa-wasm/releases/tag/ios26-safari-latest6)**

It includes:

- `ps2web.html` — browser entry point
- `ps2web.js` — JavaScript runtime
- `ps2web.wasm` — WebAssembly module
- `ps2web.data` — packaged application data

The archive does **not** include the commercial game or an ISO.

### Add your game ISO

After extracting the ZIP, place a legally obtained PS2 ISO in the **same directory as `ps2web.html`** and name it:

```text
disc.iso
```

The extracted folder should look like this:

```text
GTASA-iOS26-Safari/
├── ps2web.html
├── ps2web.js
├── ps2web.wasm
├── ps2web.data
└── disc.iso
```

### Run the prebuilt build

From the repository root, start the included server:

```bash
python3 scripts/serve.py /path/to/GTASA-iOS26-Safari /path/to/GTASA-iOS26-Safari/disc.iso
```

Replace the example paths with the actual paths on your computer. Then open:

```text
http://localhost:8620/
```

Keep the server running while playing. It supports HTTP byte ranges and sends the cross-origin isolation headers required by the WebAssembly build.

## Build from source

Use this section if you want to create the browser build yourself.

### Requirements

You will need the project's build dependencies and tools, including the PS2 Web Recomp toolchain, plus a legally obtained PS2 game ISO. The first build may take some time while dependencies are prepared.

### 1. Place the ISO

From the repository root, create the game directory and place your ISO there:

```text
Gta-sa-wasm/
├── games/
│   └── gtasa/
│       └── disc.iso
├── scripts/
└── ...
```

The exact ISO path must be:

```text
games/gtasa/disc.iso
```

**Do not put the ISO in `build/`, `docs/`, or the repository root. Do not commit or upload it to GitHub.**

### 2. Process the game and build

Run this from the repository root:

```bash
scripts/port.sh gtasa games/gtasa/disc.iso
```

### 3. Build the iOS Safari variant

After the port step succeeds:

```bash
PS2_WEB_SAFARI26=ON scripts/build_web.sh gtasa
```

The output directory is:

```text
build/web-gtasa-safari/
```

### 4. Start the local server

```bash
python3 scripts/serve.py build/web-gtasa-safari games/gtasa/disc.iso --game games/gtasa
```

Open **http://localhost:8620/** in your browser.

### Build output

A successful Safari build produces files similar to:

```text
build/
└── web-gtasa-safari/
    ├── ps2web.html
    ├── ps2web.js
    ├── ps2web.wasm
    └── ps2web.data
```

### Using another web server?

Your server must:

- Support HTTP byte-range requests.
- Send the following response headers:

```http
Cross-Origin-Opener-Policy: same-origin
Cross-Origin-Embedder-Policy: require-corp
```

Without byte-range support and cross-origin isolation, the build may fail to initialize.

## Controls

The browser build supports touch controls and gamepads. The keyboard mapping is:

| Keyboard | PS2 control |
|:--|:--|
| `Z` | Cross |
| `X` | Circle |
| `A` | Square |
| `S` | Triangle |
| `Q` / `W` / `1` / `2` | Shoulder buttons |
| `Enter` | Start |
| `Backspace` | Select |
| Arrow keys | D-pad |
| `I` / `J` / `K` / `L` | Left stick |
| `F` | Fullscreen |

## Notes

- This is an unofficial technical project; compatibility and performance are still being explored.
- No commercial game files or disc images are distributed by this repository.
- Use only a game image you are legally entitled to use.
- Do not upload, share, or commit copyrighted game files.

## Credits & legal

Built on the work of the [PS2 Web Recomp](https://github.com/ps2web/ps2web) project and its contributors.

Grand Theft Auto, Grand Theft Auto: San Andreas, and all related names and marks belong to their respective owners. This project is unofficial and is not affiliated with, endorsed by, or sponsored by Rockstar Games or Sony Interactive Entertainment.

Original code in this repository is licensed under the [MIT License](LICENSE). Third-party components remain subject to their own licenses and notices.
