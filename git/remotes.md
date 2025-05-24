# Remote Repository

## Introduction

Remote repositories are versions of your project that are hosted on the internet
or network somewhere. You can have several of them, each of which generally is
either read-only or read/write for you. Working with others involves managing
these remote repositories and pushing and pulling data to and from them when you
need to share work.

## Listing the remotes

Use the `remote` command to show all the shortnames of each remote handle you've
specified.

```fish
git remote
```

You can also use the `-v` flag to show you the URLs of those remotes.

```fish
git remote -v
```

If you want to see more info about a remote, then run: `git remote show <remote_name>`.
This command will show you the HEAD branch, remote branches, local branches that are
configured for `git pull`, and local refs that are configured for `git push`.

```sh
$ git remote show origin
* remote origin
  URL: https://github.com/my-org/complex-project
  Fetch URL: https://github.com/my-org/complex-project
  Push  URL: https://github.com/my-org/complex-project
  HEAD branch: master
  Remote branches:
    master                           tracked
    dev-branch                       tracked
    markdown-strip                   tracked
    issue-43                         new (next fetch will store in remotes/origin)
    issue-45                         new (next fetch will store in remotes/origin)
    refs/remotes/origin/issue-11     stale (use 'git remote prune' to remove)
  Local branches configured for 'git pull':
    dev-branch merges with remote dev-branch
    master     merges with remote master
  Local refs configured for 'git push':
    dev-branch                     pushes to dev-branch                     (up to
date)
    markdown-strip                 pushes to markdown-strip                 (up to
date)
    master                         pushes to master                         (up to
date)
```

**N.B.:** `git clone` command implicitly adds the `origin` remote for us.

## Adding remotes

To add a remote explicitly, use the following command:

```fish
git remote add <shortname> <url>

git remote add xyz https://github.com/Twaha-Rahman/xyz.git
```

## Fetching and pulling from remotes

To get data from your remote projects, run:

```fish
git fetch <remote_name>

git fetch xyz
```

**N.B.:** The `fetch` command only downloads the data to your local repository,
it doesn't automatically merge it. You'll have to manually merge it.

If your current branch is set up to track a remote branch, you can use the
`git pull` command to automatically fetch and then merge that remote branch into
your current branch. This may be an easier or more comfortable workflow for you;
and by default, the `git clone` command automatically sets up your local master
branch to track the remote master branch (or whatever the default branch is
called) on the server you cloned from. Running `git pull` generally fetches data
from the server you originally cloned from and automatically tries to merge it
into the code you’re currently working on.

```fish
git pull
```

## Pushing to remotes

Run the following command to push to a remote:

```fish
git push <remote> <branch>

git push origin master
```
