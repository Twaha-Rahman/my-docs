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

**N.B.:** `git clone` command implicitly adds the `origin` remote for us.

## Adding remotes

To add a remote explicitly, use the following command:

```fish
git remote add <shortname> <url>

git remote add xyz https://github.com/Twaha-Rahman/xyz
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
