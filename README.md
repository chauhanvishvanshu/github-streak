# GitHub Streak Auto Commit Project

Automatically maintain your GitHub contribution streak by committing `.cpp` files from a `staging/` folder to a `daily/` folder daily at a fixed time.

---

## Features

* Sequentially picks `.cpp` files from `staging/` folder
* Copies them to `daily/` folder daily
* Auto commit & push using GitHub Actions
* Contribution graph updates automatically
* No manual token required

---

## Update Profile Graph

**File:** `.github/workflows/daily_commit.yml`

Update commit instructions:

```bash
# Default by GitHub Actions bot
git config user.name "github-actions[bot]"
git config user.email "github-actions[bot]@users.noreply.github.com"

# Replace with your name and verified email
git config user.name "Vishvanshu Chauhan"
git config user.email "chauhanvishvanshu@gmail.com"
```

---

## Folder Structure

```
.
├── .github
│   └── workflows
│       └── daily_commit.yml
├── staging/
│   ├── file1.cpp
│   ├── file2.cpp
│   └── ...
├── daily/
│   └── (auto-generated files)
└── README.md
```

* **staging/** → Add your `.cpp` files
* **daily/** → Auto-filled by workflow
* **.github/workflows/daily_commit.yml** → Workflow config

---

## Setup Instructions for New Users

### Step 1: Fork / Clone Repo

```bash
git clone https://github.com/chauhanvishvanshu/github-streak.git
cd github-streak
```

### Step 2: Add `.cpp` Files

Place all your `.cpp` files inside the `staging/` folder.
Ensure at least one file exists.

### Step 3: Push Workflow to GitHub

```bash
git add .
git commit -m "Initial commit: setup GitHub streak project"
git push -u origin main
```

### Step 4: Enable GitHub Actions

1. Go to your repository → **Settings → Actions → General**
2. Workflow permissions → Set to **Read and write**
3. Actions → **Allow all actions and reusable workflows**

### Step 5: Run Workflow Manually (First Time)

* Go to **Actions** tab → **Daily Auto Commit (Sequential)**
* Click **Run workflow** → branch **main**
* Wait for workflow to complete

**Expected Result:**

* `daily/` folder now has the first file
* Commit `"Daily commit: YYYY-MM-DD"` created
* Contribution graph reflects the commit

### Step 6: Automatic Daily Run

Workflow scheduled to run daily at **12:31 PM IST** (changeable in cron schedule).

| Local Time Zone  | Equivalent UTC Cron                        |
| ---------------- | ------------------------------------------ |
| IST (India)      | `1 7 * * *` → 12:31 PM IST                 |
| EST (US Eastern) | `1 2 * * *` → 2:01 AM EST                  |
| PST (US Pacific) | `1 23 * * *` → 11:01 PM PST (previous day) |
| UTC              | `1 7 * * *` → 7:01 AM UTC                  |

### Step 7: Sequential File Picking

* `.tracker/last_index` keeps track of the last picked file
* Each day workflow picks the next `.cpp` file
* Loops back after reaching the last file

### Step 8: Verify Workflow & Graph

* **Actions Tab** → Workflow run status
* **daily/** folder → New file added
* **Commits Tab** → `"Daily commit: YYYY-MM-DD"`
* **Contribution Graph** → Green square for the day

### Step 9: Optional Tips

* Add `daily/.gitkeep` to make empty folder visible from start
* Ensure branch protection allows workflow push or temporarily disable
* All future commits run automatically, maintaining streak

---

## Workflow Diagram

```
staging/ (.cpp files)
        │
        ▼
GitHub Actions Workflow (daily_commit.yml)
        │
        ├─ Pick next .cpp file (sequential)
        ├─ Copy to daily/
        ├─ Commit changes
        └─ Push to GitHub (GITHUB_TOKEN)
        │
        ▼
Contribution Graph updated daily
```
