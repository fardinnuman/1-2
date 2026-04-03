<div align="center">

# <a href="https://archiveprogram.github.com/"><img src="https://raw.githubusercontent.com/acervenky/animated-github-badges/master/assets/acbadge.gif" width="26" height="25"></a> Portfolio • Fardin Numan <a href="https://archiveprogram.github.com/"><img src="https://raw.githubusercontent.com/acervenky/animated-github-badges/master/assets/acbadge.gif" width="26" height="25"></a>

![License](https://img.shields.io/badge/License-MIT-orange)
![Platform](https://img.shields.io/badge/Platform-Browser-brightgreen)
![Tech](https://img.shields.io/badge/Tech-JS%20%7C%20HTML%20%7C%20CSS-blue)

</div>

**A personal portfolio** website showcasing my skills, projects, achievements and journey as a CSE student at RUET ✨

## 📑 TABLE OF CONTENTS

- [🚀 Live Demo](#-live-demo)
- [✨ Features](#-features)
- [🛠️ Technologies Used](#️-technologies-used)
- [🏗️ Project Structure](#️-project-structure)
- [🎨 Color Palette](#-color-palette)
- [📱 Responsive Design](#-responsive-breakpoints)
- [🚦 Performance Optimizations](#-performance-optimizations)
- [🔴 Local Development](#-local-development)
- [⚖️ License](#️-license)
- [🌎 Connect With Me](#-connect-with-me)
- [🙏 Acknowledgements](#-acknowledgements)

## 🚀 LIVE DEMO

Visit the live website: **[fardinnuman.me](https://fardinnuman.me)**

## 📸 PREVIEW

![Portfolio](assets/videos/preview.gif)

## ✨ FEATURES

### 🎨 Visual & Interactive Elements

- 🪄 **Cyberpunk Aesthetic** - Neon cyan/magenta color scheme with glowing effects
- 🎭 **Interactive Animations** - Smooth scroll animations, glitch effects, and floating elements
- 🌌 **Dynamic Backgrounds** - Particle.js network and Matrix-style falling code animation
- 📱 **Fully Responsive** - Optimized for all devices from mobile to 4K displays
- 🎯 **Modular Architecture** - Cleanly organized CSS and JavaScript modules
- 🚀 **Performance Optimized** - Lazy loading, intersection observers, and efficient animations
- 🧭 **Navigation** - Adaptive navigation bar (Vertical on Desktop, Horizontal on Mobile)
- 📄 **Downloadable CV** - One click PDF download functionality

### 🚀 Sections

- **🏠 Home** - Animated introduction with glitch effect
- **👤 About** - Personal bio and social links
- **🧠 Skills** - Progress bars for technical competencies
  - Categorized skill sets:
    - **Programming** (C, C++, Java)
    - **Web Development** (HTML, CSS, JavaScript)
    - **AI/ML** (Python, Machine Learning, TensorFlow)
    - **Tools & IDEs** (Git, Linux, VS Code, Sublime Text, Atom)
    - **Creative Suite** (MS Office, Adobe Creative, Notion, Obsidian, Canva)
- **🗂️ Projects** - Interactive cards showcasing:
  - **Portfolio** - Personal portfolio website
  - **Automated Scratch Card System** (C based prepaid recharge simulator)
  - **CampusOS** (Campus communication dashboard concept)
  - **Playlist** (Interactive web music player)
  - Coverix (Cover Page Generator)
  - **Tic Tac Toe** (Game with AI opponent using Minimax)
  - **MyCash** (C++ digital wallet simulation)
  - **Tasko** (Eisenhower Matrix)
- **🏆 Achievements** - Academic awards and scholarships (PSC, JSC, SSC)
- **🎓 Education** - Timeline of educational journey
- **📧 Contact** - Email and social media links

## 🛠️ TECHNOLOGIES USED

### 🧩 Frontend
| Technology | Purpose |
|------------|---------|
| **HTML5** | Structure and semantics |
| **CSS3** | Styling, animations, responsive design |
| **JavaScript** | Interactivity, animations, DOM manipulation |

### 📦 Libraries & APIs
| Library | Purpose |
|---------|---------|
| **[Particle.js](https://vincentgarreau.com/particles.js/)** | Background particle network |
| **[Vanilla Tilt.js](https://micku7zu.github.io/vanilla-tilt.js/)** | 3D tilt effect on project cards |
| **[Highlight.js](https://highlightjs.org/)** | Code syntax highlighting |
| **[Font Awesome 6](https://fontawesome.com/)** | Icons |
| **[Google Fonts](https://fonts.google.com/)** | Inter & Space Grotesk fonts |

## 🏗️ PROJECT STRUCTURE

```
main/
├── index.html              # Main HTML file
├── css/
│   ├── style.css           # Main CSS (imports all modules)
│   ├── variables.css       # CSS custom properties
│   ├── animations.css      # Keyframes & loading screen
│   ├── backgrounds.css     # Hero & matrix backgrounds
│   ├── navbar.css          # Navigation styles
│   ├── hero.css            # Hero section
│   ├── components.css      # Reusable components
│   ├── about.css           # About section
│   ├── skills.css          # Skills section
│   ├── projects.css        # Projects grid
│   ├── achievements.css    # Achievements cards
│   ├── education.css       # Timeline
│   ├── contact.css         # Contact section
│   ├── footer.css          # Footer styles
│   ├── responsive.css      # Media queries
│   └── utilities.css       # Helper classes
├── js/
│   ├── main.js             # Main JS
│   └── modules/            # Modular JavaScript
│       ├── loading.js
│       ├── animations.js
│       ├── vanilla-tilt.js
│       ├── smooth-scroll.js
│       ├── mouse-effects.js
│       ├── matrix-bg.js
│       ├── nav-active.js
│       ├── skills-animation.js
│       └── particles.js
└── assets/
│   ├── images/             # Profile & icon images
│   ├── videos/
│   ├── projects/           # Project thumbnails
│   └── docs/               # CV PDF
├── .gitignore              # Git ignore rules
├── CNAME                   # Custom domain (fardinnuman.me)
├── LICENSE                 # Project license (MIT)
└── README.md               # Documentation
```

## 🎨 COLOR PALETTE

| Color | Name | Hex | Usage |
|-------|------|-----|-------|
| Cyan | Neon Cyan | `#00f7ff` | Primary accent, links, glows |
| Magenta | Neon Magenta | `#ff00ff` | Secondary accent, hover effects |
| Purple | Deep Purple | `#8a2be2` | Tertiary accent, gradients |
| Dark | Primary Dark | `#0a0a0f` | Background |
| Gray | Secondary Dark | `#111827` | Card backgrounds |
| Light | Text Primary | `#E5E7EB` | Main text |
| Dim | Text Secondary | `#A0AEC0` | Secondary text |

---

## 📱 RESPONSIVE BREAKPOINTS

| Device | Breakpoint | Features |
|--------|------------|----------|
| Mobile | < 480px | Stacked layout, smaller fonts |
| Tablet | 480px - 768px | Adjusted spacing, flexible grids |
| Desktop | 768px - 1200px | Full layout with side navigation |
| Wide | > 1200px | Max-width containers, enhanced effects |

## 🚦 PERFORMANCE OPTIMIZATIONS

- **Lazy Loading** - Images and content load as user scrolls
- **Intersection Observer** - Animations trigger only when visible
- **Debounced Scroll Events** - Optimized scroll handling
- **CSS Hardware Acceleration** - Smooth animations using transforms
- **Minimal Dependencies** - Only essential external libraries

## 🔴 LOCAL DEVELOPMENT

### 🟢 Prerequisites
- Any modern web browser (Brave/Chrome/Firefox/Safari)
- Local server (recommended for full functionality)

### 🔵 Installation

**1 | Clone the repository**
```bash
git clone https://github.com/fardinnuman/fardinnuman.github.io.git
cd fardinnuman.github.io
```

**2 | Run locally**
   - Using **VS Code** with Live Server extension
   - Or use Python's built-in server:
```bash
python -m http.server 8000
```

**3 | Open in browser**
```
http://localhost:8000
```

## ⚖️ LICENSE

This project is licensed under the **MIT License** 

```license
MIT License

Copyright (c) 2026 Fardin Numan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 🌎 CONNECT WITH ME

<a href="mailto:fardinnuman@gmail.com" target="_blank"><img src="https://img.shields.io/badge/-Gmail-EA4335?style=flat&logo=gmail&logoColor=ffffff"></a>
<a href="https://facebook.com/i.fardinnuman" target="blank"><img src="http://img.shields.io/badge/-Facebook-1877F2?style=flat&logo=facebook&logoColor=white"></a>
<a href="https://instagram.com/fardinnuman" target="blank"><img src="http://img.shields.io/badge/-Instagram-E4405F?style=flat&logo=instagram&logoColor=white"></a>
<a href="https://wa.me/8801406369675" target="blank"><img src="http://img.shields.io/badge/-WhatsApp-43D854?style=flat&logo=whatsapp&logoColor=white"></a>
<a href="https://linkedin.com/in/fardinnuman" target="blank"><img src="http://img.shields.io/badge/-LinkedIn-0077B5?style=flat&logo=in-linked&logoColor=white"></a>
<a href="https://twitter.com/fardinnuman" target="blank"><img src="http://img.shields.io/badge/-X-000000?style=flat&logo=x&logoColor=white"></a>

## 🙏 ACKNOWLEDGEMENTS

- **Particles.js** - Vincent Garreau for the amazing particle library
- **Vanilla Tilt** - Sergiu for the 3D tilt effect
- **Font Awesome** - For the comprehensive icon set
- **Google Fonts** - Space Grotesk and Inter fonts
- **Highlight.js** - For code syntax highlighting

<div align="center">
  
<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&height=110&color=gradient&text=Built%20with%20♡%20by%20Fardin%20Numan&reversal=false&section=footer&fontSize=42&animation=twinkling&fontAlignY=80">

</div>