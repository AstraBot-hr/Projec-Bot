
<!-- Project Title -->
<h1 align="center"> ASTRA Bot</h1>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre>
<p align="center"><strong>Autonomous ESP32 Vehicle | RC Car</strong></p>
<!-- Hero Image -->
<p align="center">
  <img src="https://images.unsplash.com/photo-1550432163-9cb326104944?q=80&w=2070&auto=format&fit=crop" alt="AstraBot ESP32 Car" width="400" style="border-radius:8px;"/>
</p>
</pre>
</div>

<!-- Boot Sequence -->
<h2 align="center"> “SYSTEM BOOT SEQUENCE INITIATED…”</h2>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre>
<h3 align="center">CONTROL LOGIC ONLINE</h3>
</pre>
</div>
<!-- About the Project -->
<h2 align="center"> About the Project</h2>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre>
<p align="center">
Astra Car is a programmable Smartcar built with modular sensors and control logic.<br>
It is designed for ESP32 control and modular sensor expansion, enabling autonomous navigation and experimentation with robotics.<br>
📸 Photo courtesy of Unsplash.
</p>
</pre>
</div>
<!-- System Architecture -->
<h2 align="center"> System Architecture</h2>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre>

<p align="center" style="font-family:monospace; font-size:16px; background-color:#f0f4f8; border-radius:6px; display:inline-block; padding:12px;">
Sensors (Line → Ultrasonic → IR)<br>
↓<br>
ESP32 Control Logic<br>
↓<br>
Drive Motors / Wheels<br>
↑<br>
Feedback / Sensor Loop
</p>
</pre>
</div>
<h2 align="center">💻 Build & Run the Project</h2>
<div style="text-align:left; width:100%;">

  <div style="display:flex; align-items:center; background-color:#f4f4f4; padding:4px 8px; border-radius:6px; margin:4px 0; width:100%;">
    <pre style="margin:0;"><code>mkdir -p cmake-build-debug</code></pre>
    <button style="margin-left:auto;" onclick="navigator.clipboard.writeText('mkdir -p cmake-build-debug')"></button>
  </div>

  <div style="display:flex; align-items:center; background-color:#f4f4f4; padding:4px 8px; border-radius:6px; margin:4px 0; width:100%;">
    <pre style="margin:0;"><code>cd cmake-build-debug</code></pre>
    <button style="margin-left:auto;" onclick="navigator.clipboard.writeText('cd cmake-build-debug')"></button>
  </div>

  <div style="display:flex; align-items:center; background-color:#f4f4f4; padding:4px 8px; border-radius:6px; margin:4px 0; width:100%;">
    <pre style="margin:0;"><code>cmake ..</code></pre>
    <button style="margin-left:auto;" onclick="navigator.clipboard.writeText('cmake ..')"></button>
  </div>

  <div style="display:flex; align-items:center; background-color:#f4f4f4; padding:4px 8px; border-radius:6px; margin:4px 0; width:100%;">
    <pre style="margin:0;"><code>cmake --build . -j6</code></pre>
    <button style="margin-left:auto;" onclick="navigator.clipboard.writeText('cmake --build . -j6')"></button>
  </div>

  <div style="display:flex; align-items:center; background-color:#f4f4f4; padding:4px 8px; border-radius:6px; margin:4px 0; width:100%;">
    <pre style="margin:0;"><code>./Project_Ep20</code></pre>
    <button style="margin-left:auto;" onclick="navigator.clipboard.writeText('./Project_Ep20')"></button>
  </div>

</div>


<!-- Git & GitHub Documentation -->
<h2 align="center">🗂 Git & GitHub Documentation (SSH Workflow)</h2>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre>
<p align="center">
This guide explains how to set up SSH with GitHub on macOS, clone repositories, manage branches, and push commits. Assumes macOS + Terminal.
</p>
</pre>
</div>
<div style="text-align:center; background-color:#e6f2ff; border-radius:8px; padding:12px; margin:20px 0;">
<h3>What is SSH and why use it?</h3>
<p>SSH allows your computer to securely communicate with GitHub without repeatedly entering usernames or passwords. Once configured, GitHub trusts your machine.</p>
</div>

<div style="text-align:center; background-color:#fff3e6; border-radius:8px; padding:12px; margin:20px 0;">
<h3>Create an SSH Key (one-time setup)</h3>

<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>ssh-keygen -t ed25519 -C "your-github-username"</code></pre>
<button onclick="navigator.clipboard.writeText('ssh-keygen -t ed25519 -C \"your-github-username\"')"></button>
</div>

<p>Press Enter for file location, optionally enter a passphrase. Creates <code>~/.ssh/id_ed25519</code> (private) and <code>~/.ssh/id_ed25519.pub</code> (public).</p>

<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519</code></pre>
<button onclick="navigator.clipboard.writeText('eval \"$(ssh-agent -s)\"\\nssh-add ~/.ssh/id_ed25519')"></button>
</div>

<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>pbcopy < ~/.ssh/id_ed25519.pub</code></pre>
<button onclick="navigator.clipboard.writeText('pbcopy < ~/.ssh/id_ed25519.pub')"></button>
</div>

<p>Add SSH key to GitHub → Settings → SSH & GPG keys → New SSH key → Title: your computer name → Paste key → Save.</p>

<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>ssh -T git@github.com</code></pre>
<button onclick="navigator.clipboard.writeText('ssh -T git@github.com')"></button>
</div>
<p>Expected output: <em>Hi USERNAME! You've successfully authenticated.</em></p>
</div>

<div style="text-align:center; background-color:#e6ffe6; border-radius:8px; padding:12px; margin:20px 0;">
<h3>Clone a repository</h3>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>git clone git@github.com:USERNAME/REPO.git
cd REPO</code></pre>
<button onclick="navigator.clipboard.writeText('git clone git@github.com:USERNAME/REPO.git\\ncd REPO')"></button>
</div>


<h3>Daily workflow (commit & push)</h3>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>git add .
git commit -m "Describe your changes"
git push</code></pre>
<button onclick="navigator.clipboard.writeText('git add .\\ngit commit -m \"Describe your changes\"\\ngit push')"></button>
</div>

<h3>Working with branches</h3>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>git checkout -b feature-name
git push -u origin feature-name
git checkout main
git checkout feature-name
git checkout main
git pull
git merge feature-name
git push</code></pre>
<button onclick="navigator.clipboard.writeText('git checkout -b feature-name\\ngit push -u origin feature-name\\ngit checkout main\\ngit checkout feature-name\\ngit checkout main\\ngit pull\\ngit merge feature-name\\ngit push')"></button>
</div>

<h3>Useful Git commands</h3>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>git status
git branch
git log --oneline
git remote -v</code></pre>
<button onclick="navigator.clipboard.writeText('git status\\ngit branch\\ngit log --oneline\\ngit remote -v')"></button>
</div>

<h3>Common errors & fixes</h3>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>“not a git repository” → Use cd to enter correct folder.
Asked for username/password → Remote is HTTPS. Fix: git remote set-url origin git@github.com:USERNAME/REPO.git</code></pre>
<button onclick="navigator.clipboard.writeText('“not a git repository” → Use cd to enter correct folder.\\nAsked for username/password → Remote is HTTPS. Fix: git remote set-url origin git@github.com:USERNAME/REPO.git')"></button>
</div>

<h3>Minimal cheat sheet</h3>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre><code>git add .
git commit -m "msg"
git push</code></pre>
<button onclick="navigator.clipboard.writeText('git add .\\ngit commit -m \"msg\"\\ngit push')"></button>
</div>
</div>
<div style="display:inline-block; text-align:left; background-color:#f4f4f4; padding:10px; border-radius:6px; margin:5px 0; width:100%;">
<pre>
  <span style="color:#1f2937; font-size:24px; font-weight:bold; margin:0 20px;">Hogeschool Rotterdam</span>
  <span style="color:#1f2937; font-size:24px; font-weight:bold; margin:0 20px;">Project E20</span>
  <span style="color:#1f2937; font-size:24px; font-weight:bold; margin:0 20px;">Author: Nathanial</span>
</pre>
</div>
